class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool>dp(n+1,1);
        dp[1]=0;
        
        for(int i=2;i*i<=n;i++)
        {
            if(dp[i])
            {
                for(int j=2*i;j<=n;j+=i)
                    dp[j]=0;
            }
        }
        int c=0;
        for(int i=2;i<n;i++)
            c+=dp[i];
        
        return c;
    }
};