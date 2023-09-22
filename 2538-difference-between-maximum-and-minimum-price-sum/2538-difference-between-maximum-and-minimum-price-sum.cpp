#define ll long long
class Solution {
    ll dp[100100][2];
    ll res=0;
    void dfs(vector<int>g[],int n,int p,vector<int>& price) {
        dp[n][0]=price[n];
        for(int c:g[n]) {
            if(c!=p) {
                dfs(g,c,n,price);
                res=max(res,dp[n][0]+dp[c][1]);
                res=max(res,dp[n][1]+dp[c][0]);
                dp[n][0]=max(dp[n][0],dp[c][0]+price[n]);
                dp[n][1]=max(dp[n][1],dp[c][1]+price[n]);
            }
        }
    }
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<int>g[n];
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        dfs(g,0,-1,price);
        return res;
    }
};