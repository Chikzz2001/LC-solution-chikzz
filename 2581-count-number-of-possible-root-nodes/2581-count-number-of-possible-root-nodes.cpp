class Solution {
    set<vector<int>>G;
    vector<int>dp;
    void dfs(vector<int>g[],int n,int p) {
        for(int c:g[n]) {
            if(c!=p) {
                if(G.count({n,c}))dp[0]++;
                dfs(g,c,n);
            }
        }
    }
    
    void reroot(vector<int>g[],int n,int p) {
        for(int c:g[n]) {
            if(c!=p) {
                bool up=G.count({c,n});
                bool down=G.count({n,c});
                dp[c]=dp[n];
                if(up&!down)dp[c]++;
                if(!up&down)dp[c]--;
                reroot(g,c,n);
            }
        }
    }
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        for(auto x:guesses) {
            G.insert(x);
        }
        int n=edges.size()+1;
        dp=vector<int>(n,0);
        vector<int>g[n];
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        dfs(g,0,-1);
        reroot(g,0,-1);
        
        int r=0;
        for(int i=0;i<n;i++) {
            r+=(dp[i]>=k);
        }
        
        return r;
        
    }
};
