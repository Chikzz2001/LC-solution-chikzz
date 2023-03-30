class Solution {
    int dp[31][31][31];
    int valid(string &s1,string &s2,int i1,int i2,int len)
    {
        if(dp[i1][i2][len]!=-1)
            return dp[i1][i2][len];
        
        if(s1.substr(i1,len)==s2.substr(i2,len))
            return dp[i1][i2][len]=1;
        
        for(int i=1;i<len;i++)
        {
            if((valid(s1,s2,i1,i2,i)&valid(s1,s2,i1+i,i2+i,len-i))||(valid(s1,s2,i1,i2+len-i,i)&valid(s1,s2,i1+i,i2,len-i)))
               return dp[i1][i2][len]=1;
        }
        
        return dp[i1][i2][len]=0;
    }
public:
    bool isScramble(string s1, string s2) 
    {
        int n=s1.length();
        if(n!=s2.length())return 0;
        
        memset(dp,-1,sizeof(dp));
        return valid(s1,s2,0,0,n)?1:0;
    }
};

//a bc a bc
//a cb ab c
               
