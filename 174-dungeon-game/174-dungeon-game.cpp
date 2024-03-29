class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int n=dungeon.size(),m=dungeon[0].size();
        int dp[n][m];
        dp[n-1][m-1]=min(0,dungeon[n-1][m-1]);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1&&j==m-1)continue;
                if(i==n-1)
                    dp[i][j]=min(0,dp[i][j+1]+dungeon[i][j]);
                else if(j==m-1)
                    dp[i][j]=min(0,dp[i+1][j]+dungeon[i][j]);
                else
                    dp[i][j]=min(0,max(dp[i+1][j],dp[i][j+1])+dungeon[i][j]);
            }
        }
        return -dp[0][0]+1;
    }
};