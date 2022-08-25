class Solution {
    const int M=1e9+7;
public:
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        
        int dp[n+1][m+1];
        //dp[i][j]-->tells the maximum no of subseqs of substring t[0:j-1] in s[0:i-1]
        
        //we can generate one subseqs of 0 length from any substring s[0,i-1]
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        
        //we can not generate any subseq from 0 length of s
        for(int i=1;i<=m;i++)
            dp[0][i]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //we can add t[j-1] to all subseqs generated till t[0:j-2] from s[0:i-2]
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=(dp[i-1][j]%M+dp[i-1][j-1]%M)%M;
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};