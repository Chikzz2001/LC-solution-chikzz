#define ll long long int
class Solution {
    const int M=1e9+7;
public:
    int countHousePlacements(int n) 
    {
        ll dp[n+1][2][2];
        //dp[curent pos][upper_filled][lower_filled]
        
        dp[1][0][0]=dp[1][1][0]=dp[1][0][1]=dp[1][1][1]=1;
        
        for(int i=2;i<=n;i++)
        {
            dp[i][0][0]=(dp[i-1][0][0]%M+dp[i-1][1][0]%M+dp[i-1][0][1]%M+dp[i-1][1][1]%M)%M;
            dp[i][1][0]=(dp[i-1][0][0]%M+dp[i-1][0][1]%M)%M;
            dp[i][0][1]=(dp[i-1][0][0]%M+dp[i-1][1][0]%M)%M;
            dp[i][1][1]=dp[i-1][0][0]%M;
        }
        ll res=(dp[n][0][0]%M+dp[n][0][1]%M+dp[n][1][0]%M+dp[n][1][1]%M)%M;
        return res;
    }
};

