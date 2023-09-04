class Solution {
    int dp[10002][20];
    int lvl[10002];
    int dp2[27][10002];
    
    int lift_node(int u,int d)
    {
        if(!d)return u;
        int c=0;
        while(d) {
            if(d&1)u=dp[u][c];
            c++;
            d>>=1;
        }
        return u;
    }
    
    void dfs(vector<vector<pair<int,int>>>& g,int n,int p,int W,int l) {
        lvl[n]=l;
        dp[n][0]=p;
        for(auto [c,wt]:g[n]) {
            if(c!=p) {
                dp2[W][c]+=wt+dp2[W][n];
                dfs(g,c,n,W,l+1);
            }
            
        }
    }
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<vector<pair<int,int>>>>g(27,vector<vector<pair<int,int>>>(n+1));
        
        for(int i=1;i<=26;i++) {
            for(auto &e:edges) {
                g[i][e[1]+1].push_back({e[0]+1,(e[2]==i?0:1)});
                g[i][e[0]+1].push_back({e[1]+1,(e[2]==i?0:1)});
            }
        }
      
        int root=1;
        // cout<<root<<"\n";
        for(int i=1;i<=26;i++) {
            dfs(g[i],1,1,i,0);
        }
        // for(int i=0;i<n;i++)cout<<i<<" "<<dp[i][0]<<"\n";
        
        //binary-lifting(form the parent-child relation)
        //dp[i][j] stores the (2^j)th parent of i
         for(int j=1;j<20;j++) {
            for(int i=1;i<=n;i++) {
                if(dp[i][j-1])dp[i][j]=dp[dp[i][j-1]][j-1];
            }
        }
        
        // for(int i=1;i<=n;i++) {
        //     for(int j=0;j<20;j++)cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        // for(int i=1;i<=n;i++) {
        //     cout<<lvl[i]<<"\n";
        // }
        
        vector<int>res;
        for(auto q:queries) {
            q[0]++;
            q[1]++;
            int u=q[0],v=q[1],lca;
            if(lvl[u]>lvl[v])
            u=lift_node(u,lvl[u]-lvl[v]);
            else
            v=lift_node(v,lvl[v]-lvl[u]);
            if(u==v)lca=u;
            else if(min(u,v)==root)lca=root;
            else {
                for(int i=19;i>=0;i--)
                {
                    if(dp[u][i]!=dp[v][i])
                    {
                        u=dp[u][i];
                        v=dp[v][i];
                    }
                }
                lca=dp[u][0];
            }
            // if(q[0]==5&&q[1]==7)cout<<lca<<"\n";
            int minn=1e9;
            for(int i=1;i<=26;i++) {
                // if(q[0]==5&&q[1]==7)cout<<i<<" "<<dp2[i][lca]<<" "<<dp2[i][q[0]]<<" "<<dp2[i][q[1]]<<"\n";
                minn=min(minn,-(2*dp2[i][lca]-dp2[i][q[0]]-dp2[i][q[1]]));
            }
            res.push_back(minn);
        }
        
        return res;
    }
};