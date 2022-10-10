#define ll long long int
class Solution {
    const int M=1e9+7;
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(m,vector<ll>(k,0)));
        dp[n-1][m-1][grid[n-1][m-1]%k]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1&&j==m-1)continue;
                else if(i==n-1)
                {
                    for(int K=0;K<k;K++)
                        dp[i][j][(grid[i][j]+K)%k]=dp[i][j+1][K];
                }
                else if(j==m-1)
                {
                    for(int K=0;K<k;K++)
                        dp[i][j][(grid[i][j]+K)%k]=dp[i+1][j][K];
                }
                else
                {
                    for(int K=0;K<k;K++)
                        dp[i][j][(grid[i][j]+K)%k]=(dp[i][j][(grid[i][j]+K)%k]%M+dp[i][j+1][K]%M)%M;
                    for(int K=0;K<k;K++)
                        dp[i][j][(grid[i][j]+K)%k]=(dp[i][j][(grid[i][j]+K)%k]%M+dp[i+1][j][K]%M)%M;
                }
            }
        }
        return dp[0][0][0]%M;
    }
};