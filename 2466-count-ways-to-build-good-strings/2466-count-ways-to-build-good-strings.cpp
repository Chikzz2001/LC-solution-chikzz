#define ll long long
class Solution {
    ll dp[100100];
    const int M=1e9+7;
    int helper(int n,int i,int z,int o) {
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        ll res=0;
        if(i+z<=n) {
            res=(res+1+helper(n,i+z,z,o)%M)%M;
        }
        if(i+o<=n) {
            res=(res+1+helper(n,i+o,z,o)%M)%M;
        }
        return dp[i]=res;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        ll r1=helper(high,0,zero,one);
         memset(dp,-1,sizeof(dp));
        ll r2=helper(low-1,0,zero,one);
        return (r1-r2+M)%M;
    }
};