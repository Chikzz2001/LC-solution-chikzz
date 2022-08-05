class Solution {
    long long int dp[16][16][2];
    bool zero_present=0;
public:
    int maxProductPath(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        
        if(grid[n-1][m-1]==0)zero_present=1;
        dp[n-1][m-1][0]=min(0,grid[n-1][m-1]);
        dp[n-1][m-1][1]=max(0,grid[n-1][m-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(grid[i][m-1]==0)zero_present=1;
            if(grid[i][m-1]>=0)
            dp[i][m-1][1]=1LL*dp[i+1][m-1][1]*grid[i][m-1],dp[i][m-1][0]=1LL*dp[i+1][m-1][0]*grid[i][m-1];
            else
            dp[i][m-1][1]=1LL*dp[i+1][m-1][0]*grid[i][m-1],dp[i][m-1][0]=1LL*dp[i+1][m-1][1]*grid[i][m-1];
        }
        for(int i=m-2;i>=0;i--)
        {
            if(grid[n-1][i]==0)zero_present=1;
            if(grid[n-1][i]>=0)
            dp[n-1][i][1]=1LL*dp[n-1][i+1][1]*grid[n-1][i],dp[n-1][i][0]=1LL*dp[n-1][i+1][0]*grid[n-1][i];
            else
            dp[n-1][i][1]=1LL*dp[n-1][i+1][0]*grid[n-1][i],dp[n-1][i][0]=1LL*dp[n-1][i+1][1]*grid[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(grid[i][j]>=0)
                {
                    if(grid[i][j]==0)zero_present=1;
                    dp[i][j][0]=1LL*grid[i][j]*min(dp[i+1][j][0],dp[i][j+1][0]);
                    dp[i][j][1]=1LL*grid[i][j]*max(dp[i+1][j][1],dp[i][j+1][1]);
                }
                else
                {
                    dp[i][j][0]=1LL*grid[i][j]*max(dp[i+1][j][1],dp[i][j+1][1]);
                    dp[i][j][1]=1LL*grid[i][j]*min(dp[i+1][j][0],dp[i][j+1][0]);
                }
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //         cout<<dp[i][j][0]<<","<<dp[i][j][1]<<" ";
        //     cout<<"\n";
        // }
        return dp[0][0][1]==0&&!zero_present?-1:dp[0][0][1]%1000000007;
    }
};