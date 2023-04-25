#define ll long long
class Solution {
    ll dp[201][201];
public:
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        for(auto p:prices) {
            dp[p[0]][p[1]]=p[2];
        }
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                for(int k=1;k<=i;k++) {
                    dp[i][j]=max(dp[i][j],dp[k][j]+dp[i-k][j]);
                }
                for(int k=1;k<=j;k++) {
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[i][j-k]);
                }
            }
        }
        
        return dp[n][m];
    }
};