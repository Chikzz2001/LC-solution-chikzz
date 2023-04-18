class Solution {
    int nodes[51];
    int dp[55][55][2];
    int dfs(vector<int>g[],int n,int p,vector<int>& price,int take) {
        int minn=1e9,res=0;
        if(dp[n][p][take]!=-1)return dp[n][p][take];
        //half
        if(!take) {
            int res=nodes[n]*(price[n]/2);
            for(int c:g[n]) {
                if(c!=p) {
                    res+=dfs(g,c,n,price,1);
                }
            }
            minn=min(minn,res);
            res=0;
        }
        //don't
        res=nodes[n]*price[n];
        for(int c:g[n]) {
            if(c!=p) {
                res+=dfs(g,c,n,price,0);
            }
        }
        minn=min(minn,res);
        return dp[n][p][take]=minn;
    }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<int>g[n];
        for(auto &e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        for(auto &t:trips) {
            vector<int>P(n,-1);
            queue<int>q;
            q.push(t[0]);
            while(!q.empty()) {
                int curr=q.front();q.pop();
                for(int nbr:g[curr]) {
                    if(P[nbr]==-1) {
                        P[nbr]=curr;
                        q.push(nbr);
                    }
                }
            }
            int x=t[1];
            while(x!=t[0]) {
                nodes[x]++;
                x=P[x];
            }
            nodes[t[0]]++;
        }
        
        memset(dp,-1,sizeof(dp));
        return dfs(g,trips[0][0],n,price,0);
    }
};