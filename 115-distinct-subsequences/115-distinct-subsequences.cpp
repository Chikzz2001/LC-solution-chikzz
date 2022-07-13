#define ll long long int
class Solution {
    const int M=1e9+7;
public:
    int numDistinct(string s, string t) 
    {
        int n=s.length(),m=t.length();
    ll dp[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    dp[i][0]=1;
    for(int i=1;i<=m;i++)
    dp[0][i]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j]=(dp[i-1][j]%M+dp[i-1][j-1]%M)%M;
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][m];
    }
};