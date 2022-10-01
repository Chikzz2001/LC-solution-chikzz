class Solution {
    int dp[101];
    int ways(string &s,int i)
    {
        if(i==s.length())return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        
        if(s[i]=='0')
            return dp[i]=0;
        
        int one=0,two=0;
        one=ways(s,i+1);
        if(i<s.length()-1)
        {
            if(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6'))
                two=ways(s,i+2);
        }
        return dp[i]=one+two;
    }
public:
    int numDecodings(string s) 
    {
        memset(dp,-1,sizeof(dp));
        ways(s,0);
        return dp[0];
    }
};