#define ll long long
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        int n=s1.length(),m=s2.length();
        
        //dp[i][j] stores the minimum ascii value required to delete to make s1(0--->i) 
        //s2(0--->j) equal
        
        int dp[n+1][m+1];
        
        dp[0][0]=0;
        
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
           sum+=s1[i-1];
           dp[i][0]=sum;
        }
        
        sum=0;
        for(int i=1;i<=m;i++)
        {
           sum+=s2[i-1];
           dp[0][i]=sum;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};