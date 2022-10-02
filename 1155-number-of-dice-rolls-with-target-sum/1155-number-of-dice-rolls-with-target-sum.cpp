#define ll long long int
class Solution {
    ll dp[31][1001];
    const int M=1e9+7;
    int K;
    ll helper(int i,int target,int n)
    {
        if(target<0)return 0;
        if(i==n)
        {
            return target==0?1:0;
        }
        
        if(dp[i][target]!=-1)return dp[i][target];
        ll tot=0;
        for(int j=1;j<=K;j++)
        {
            tot=(tot+helper(i+1,target-j,n))%M;
        }
        return dp[i][target]=tot;
    }
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        K=k;
        memset(dp,-1,sizeof(dp));
        ll res=helper(0,target,n);
        return res%M;
    }
};