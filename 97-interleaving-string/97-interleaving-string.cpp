class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        //dp[i][j]-->is true if s3 till (i+j-1)th idx can be formed by interleaving s1 and s2 till (i-1)th 
        //and (j-1)th idx respectively.
        
        int n=s1.length(),m=s2.length();
        if(n+m!=s3.length())return 0;
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        
        dp[0][0]=1;
        for(int i=1;i<=n;i++)if(s1[i-1]==s3[i-1])dp[i][0]=dp[i-1][0];
        for(int i=1;i<=m;i++)if(s2[i-1]==s3[i-1])dp[0][i]=dp[0][i-1];
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                    if(s1[i-1]==s3[i+j-1]&&dp[i-1][j])
                       dp[i][j]=1;
                    if(s2[j-1]==s3[i+j-1]&&dp[i][j-1])
                       dp[i][j]=1;
            }
        }

        return dp[n][m];
    }
};