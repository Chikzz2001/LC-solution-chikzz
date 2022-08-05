class Solution {
    vector<int>dp;
    bool win(int M,int D,int mask)
    {
        if(D<=0)return 0;
    
        if(dp[mask]!=-1)return dp[mask];
      
        for(int i=1;i<=M;i++)
        {
            if(!(mask&(1<<i)))
            {
                if(!win(M,D-i,mask|(1<<i)))
                return dp[mask]=1;
            }
        }
        return dp[mask]=0;
    }
public:
    bool canIWin(int M, int D) 
    {
        if(D==0)return 1;
        if((M*(M+1))/2<D)return 0;
        dp=vector<int>(1<<(M+1),-1);
        return win(M,D,0);
    }
};

/*

11-->1,2,3,4,...,10
18--->79

*/