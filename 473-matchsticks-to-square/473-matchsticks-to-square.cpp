class Solution {
    int N,target;
    int dp[1<<15][5];
    bool helper(vector<int>& M,int sum,int level,int &mask)
    {
        if(level==1)return 1;
        
        if(dp[mask][level]!=-1)
            return dp[mask][level];
        
        if(sum==0)
            return dp[mask][level]=helper(M,target,level-1,mask);
        
        for(int i=0;i<N;i++)
        {
            if(!(mask&(1<<i)))
            {
                mask|=(1<<i);
                if(helper(M,sum-M[i],level,mask))
                    return dp[mask][level]=1;
                mask^=(1<<i);
            }
        }
        return dp[mask][level]=0;
    }
public:
    bool makesquare(vector<int>& M) 
    {
        int sum=0;
        for(auto &x:M)sum+=x;
        N=M.size();
        if(N<4||sum%4!=0)return 0;
        target=sum/4;
        memset(dp,-1,sizeof(dp));
        int mask=0;
        return helper(M,sum/4,4,mask);
    }
};