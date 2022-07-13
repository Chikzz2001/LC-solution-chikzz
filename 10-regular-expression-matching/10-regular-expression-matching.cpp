class Solution {
    bool dp[21][31];
public:
    bool isMatch(string s, string p) 
    {
        int sl=s.length(),pl=p.length();
      
        //dp[i][j]-->true if prefix till i-1th idx of s can be matched with j-1th prefix of string p
        dp[0][0]=1;
        for(int j=1;j<=pl;j++)
            if(p[j-1]=='*')dp[0][j]=dp[0][j-2];
     
        for(int i=1;i<=sl;i++)
        {
            for(int j=1;j<=pl;j++)
            {
                if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i][j-2];
                    if(dp[i][j-2])continue;
                    for(int k=i;k>=1;k--)
                    {
                        if(s[k-1]==p[j-2]||p[j-2]=='.')
                            dp[i][j]|=dp[k][j-1];
                        else
                            break;
                    }
                }
                else if(p[j-1]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=(s[i-1]==p[j-1])&dp[i-1][j-1];
                }
            }
        }
        
        // for(int i=0;i<=sl;i++)
        // {
        //     for(int j=0;j<=pl;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        //     }
        return dp[sl][pl];
    }
};

/*
"aaabaaaababcbccbaab"
"c*c*.*c*a*..*c*"
"aab"
"b.*"
"a"
".*."
"aab"
"c*a*b"


*/