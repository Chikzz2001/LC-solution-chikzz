#define ll long long int
class Solution {
    const int M=1e9+7;
public:
    int countVowelPermutation(int n) {
        vector<vector<ll>>dp(n,vector<ll>(5,1));
        
        for(int i=1;i<n;i++)
        {
                dp[i][0]=dp[i-1][1];
                dp[i][1]=(dp[i-1][0]+dp[i-1][2])%M;
                dp[i][2]=((dp[i-1][0]+dp[i-1][1])%M+(dp[i-1][3]+dp[i-1][4])%M)%M;
                dp[i][3]=(dp[i-1][2]+dp[i-1][4])%M;
                dp[i][4]=dp[i-1][0];
        }
        
        ll res=0;
        for(int i=0;i<5;i++)
            res=(res%M+dp[n-1][i]%M)%M;
        
        return res;
    }
};