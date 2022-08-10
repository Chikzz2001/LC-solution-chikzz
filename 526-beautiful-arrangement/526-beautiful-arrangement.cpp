class Solution {
    int dp[1<<16][16];
    int ways(int n,int i,int mask)
    {
        if(i==n+1)return 1;
        
        if(dp[mask][i]!=-1)return dp[mask][i];
        
        int res=0;
        for(int j=1;j<=n;j++)
        {
            if(!(mask&(1<<j)))
               {
                    if(i%j==0||j%i==0)
                    res+=ways(n,i+1,mask|(1<<j));
               }
        }
        return dp[mask][i]=res;     
    }
public:
    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
        return ways(n,1,0);
    }
};