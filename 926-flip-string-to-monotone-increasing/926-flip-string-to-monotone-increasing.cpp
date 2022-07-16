class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int n=s.length();
        
        int dp[n][2];
        
        dp[0][0]=(s[0]=='0')?0:1,dp[0][1]=(s[0]=='1')?0:1;
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=1+min(dp[i-1][0],dp[i-1][1]);
            }
            else
            {
                dp[i][0]=1+dp[i-1][0];
                dp[i][1]=min(dp[i-1][1],dp[i-1][0]);
            }
        }
        
        return min(dp[n-1][0],dp[n-1][1]);
    }
};