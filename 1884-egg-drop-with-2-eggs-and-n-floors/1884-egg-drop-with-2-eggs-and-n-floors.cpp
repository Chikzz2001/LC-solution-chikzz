class Solution {
    int dp[1001][3];
    int minMoves(int n,int eggs)
    {
        if(n==0||n==1||eggs==1)return n;
        
        if(dp[n][eggs]!=-1)
            return dp[n][eggs];
        
        int minn=1e9,maxx=0;
        for(int i=1;i<=n;i++)
        {
           maxx=1+max(minMoves(i-1,eggs),minMoves(n-i,eggs-1)); 
           minn=min(minn,maxx);
        }
        return dp[n][eggs]=minn;
    }
public:
    int twoEggDrop(int n) 
    {
        int eggs=2;
        memset(dp,-1,sizeof(dp));
        //return minMoves(n,eggs);
        return minMoves(n,eggs);
    }
};
