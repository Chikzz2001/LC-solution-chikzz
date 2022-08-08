class Solution {
long mod=(long)Math.pow(10,9)+7;
    
    public int maxProductPath(int[][] grid) 
    {
        int n=grid.length;
        int m=grid[0].length;
        
        //dp[i][j][0]--->max value till now
        //dp[i][j][1]--->min value till now
        
        long dp[][][]=new long[n][m][2];
        dp[n-1][m-1][0]=grid[n-1][m-1];
        dp[n-1][m-1][1]=grid[n-1][m-1];
        
        for(int i=n-2;i>=0;i--)
        {
            if(grid[i][m-1]>=0)
            {
                dp[i][m-1][0]=((dp[i+1][m-1][0])*(grid[i][m-1]));
                dp[i][m-1][1]=((dp[i+1][m-1][1])*(grid[i][m-1]));
            }
            
            else
            {
                dp[i][m-1][0]=((dp[i+1][m-1][1])*(grid[i][m-1]));
                dp[i][m-1][1]=((dp[i+1][m-1][0])*(grid[i][m-1]));
            }
        }
        
        for(int i=m-2;i>=0;i--)
        {
            if(grid[n-1][i]>=0)
            {
                dp[n-1][i][0]=((dp[n-1][i+1][0])*(grid[n-1][i]));
                dp[n-1][i][1]=((dp[n-1][i+1][1])*(grid[n-1][i]));
            }
            
            else
            {
                dp[n-1][i][0]=((dp[n-1][i+1][1])*(grid[n-1][i]));
                dp[n-1][i][1]=((dp[n-1][i+1][0])*(grid[n-1][i]));
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                long max=Math.max(dp[i+1][j][0],dp[i][j+1][0]);
                long min=Math.min(dp[i+1][j][1],dp[i][j+1][1]);
                
                long curr=grid[i][j];
                
                if(curr>=0)
                {
                    dp[i][j][0]=(max*curr);
                    dp[i][j][1]=(min*curr);
                    
                }
                
                else
                {
                    dp[i][j][1]=(max*curr);
                    dp[i][j][0]=(min*curr);
                }
            }
        }

        return dp[0][0][0]>=0?(int)(dp[0][0][0]%mod):-1;
    }

}