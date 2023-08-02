class Solution {
    int dp[2001][2001];
    int helper(string &s,string &p,int i,int j) {
        if(i==-1) {
            if(j==-1)return 1;
            if(p[j]=='*')return helper(s,p,i,j-1);
            return 0;
        }
        if(j==-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int res=0;
        if(s[i]==p[j]||p[j]=='?')res=helper(s,p,i-1,j-1);
        else if(p[j]=='*')res=helper(s,p,i-1,j)|helper(s,p,i,j-1);
        return dp[i][j]=res;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        memset(dp,-1,sizeof(dp));
        return helper(s,p,n-1,m-1);
    }
};

// "adceb"
// "*a*b"
// "aab"
// "c*a*b"
// "abcabczzzde"
// "*abc???de*"
// ""
// "***"
// "aaaaaababaa"
// "a*b**"