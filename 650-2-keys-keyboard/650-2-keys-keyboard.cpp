class Solution {
    int dp[1001];
public:
    int minSteps(int n) 
    {
        if(n==1)return 0;
        
        if(dp[n])return dp[n];
        
        int minn=n;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                minn=min(minn,i+minSteps(n/i));
                minn=min(minn,n/i+minSteps(i));
            }
        }
        return dp[n]=minn;
    }
};