class Solution
{
    int dp[1<<10][10][2][2];
    int helper(string &s,int i,int mask,int lz,int bound)
    {
        if(i==s.length())return 1;
        
        if(dp[mask][i][lz][bound]!=-1)
            return dp[mask][i][lz][bound];
        
        int maxx=bound?s[i]-'0':9;
        
        int tot=0;
        
        for(int j=0;j<=maxx;j++)
        {
            if((mask&(1<<j))&&lz==0)continue;
            mask|=(1<<j);
            tot+=helper(s,i+1,mask,lz&(j==0),bound&(j==maxx));
            mask^=(1<<j);
        }
        
        return dp[mask][i][lz][bound]=tot;
    }
    public:
        int numDupDigitsAtMostN(int n)
        {
            string s=to_string(n);
            memset(dp,-1,sizeof(dp));
            int mask=0;
            int res=(n+1)-helper(s,0,mask,1,1);
            return res;
        }
};