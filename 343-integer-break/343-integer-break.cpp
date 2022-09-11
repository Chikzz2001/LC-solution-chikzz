class Solution {
    int breakint(int n,vector<int>& dp)
    {
        if(n==2)return 1;
        
        if(dp[n]!=-1)return dp[n];
        
        int maxpro=1;
        for(int i=1;i<=n-2;i++)
        {
            maxpro=max(i*breakint(n-i,dp),maxpro);
        }
        return dp[n]=max(maxpro,n);
    }
public:
    int integerBreak(int n) {
        
        //corner case
        if(n==3)return 2;
        
        vector<int>dp(n+1,-1);
        return breakint(n,dp);
    }
};