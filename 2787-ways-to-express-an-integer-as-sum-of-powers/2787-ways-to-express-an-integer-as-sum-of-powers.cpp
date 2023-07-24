class Solution {
    int X;
    int dp[301][301];
    const int M=1e9+7;
    int helper(int n,int i) {
        if(n==0)return 1;
        long long r=pow(i,X);
        if(n<r)return 0;
        if(dp[n][i]!=-1)return dp[n][i];
        int res=0;
        res=(res%M+helper(n-r,i+1)%M)%M;
        res=(res%M+helper(n,i+1)%M)%M;
        return dp[n][i]=res;
    }
public:
    int numberOfWays(int n, int x) {
        X=x;
        memset(dp,-1,sizeof(dp));
        return helper(n,1);
    }
};