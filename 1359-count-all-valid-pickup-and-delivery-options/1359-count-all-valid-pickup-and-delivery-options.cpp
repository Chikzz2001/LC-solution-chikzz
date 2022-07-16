#define ll long long int
class Solution {
    const int M=1e9+7;
    ll dp[501];
public:
    int countOrders(int n) 
    {
        if(n==1)return 1;
        
        if(dp[n])return dp[n];
        
        ll res=(1LL*n*(2*n-1)*countOrders(n-1)%M)%M;
        return dp[n]=res%M;
    }
};


/*

n*(2*n-1)*f(n-1)

*/