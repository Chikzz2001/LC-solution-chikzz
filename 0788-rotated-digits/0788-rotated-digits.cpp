class Solution {
    int dp[6][2][2][6];
    int valid[10];
    int helper(string &s,int i,int bound,int lz,int tot) {
        if(i==s.length())return tot==s.length()?0:1;
        
        if(dp[i][bound][lz][tot]!=-1)return dp[i][bound][lz][tot];
        
        int maxx=bound?s[i]-'0':9;
        
        int res=0;

        for(int j=0;j<=maxx;j++) {
            if(valid[j]!=-1)
            res+=helper(s,i+1,bound&(j==maxx),lz&(j==0),tot+valid[j]);
        }
        
        return dp[i][bound][lz][tot]=res;
    }
public:
    int rotatedDigits(int n) {
        string s=to_string(n);
        valid[0]=valid[1]=valid[8]=1;
        valid[3]=valid[4]=valid[7]=-1;
        
        memset(dp,-1,sizeof(dp));
        return helper(s,0,1,1,0);
    }
};