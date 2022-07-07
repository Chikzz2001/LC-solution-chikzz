class Solution {
    int dp[101][101];
    bool isPossible(string &s1,string &s2,string& s3,int i,int j,int k,int &n1,int &n2,int &n3)
    {
        if(k==n3&&i==n1&&j==n2)return 1;
        
        if(k>=n3||(i>=n1&&j>=n2))return 0;
        
        if(i<n1&&j<n2&&s1[i]!=s3[k]&&s2[j]!=s3[k])return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        bool f1=0,f2=0;
        if(i<n1&&s1[i]==s3[k])
            f1=isPossible(s1,s2,s3,i+1,j,k+1,n1,n2,n3);
        
        if(j<n2&&s2[j]==s3[k])
            f2=isPossible(s1,s2,s3,i,j+1,k+1,n1,n2,n3);
        
        return dp[i][j]=f1|f2?1:0;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        
        if((n1+n2)!=n3)return 0;
        memset(dp,-1,sizeof(dp));
        return isPossible(s1,s2,s3,0,0,0,n1,n2,n3);
    }
};