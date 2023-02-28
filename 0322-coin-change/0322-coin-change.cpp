class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[2][amount+1];
        
        //dp[i][j]-->minimum coins we can pick (0--i) to make j
        for(int i=0;i<=amount;i++)dp[0][i]=1e7;
        for(int i=0;i<=n;i++)dp[i&1][0]=0;
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=amount;j++) {
                dp[i&1][j]=min(dp[(i-1)&1][j],1+(j-coins[i-1]>=0?dp[i&1][j-coins[i-1]]:(int)1e7));
            }
        }
        
        return dp[n&1][amount]==1e7?-1:dp[n&1][amount];
    }
};