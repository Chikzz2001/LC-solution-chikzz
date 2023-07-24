#define ll long long
class Solution {
    double Pow(double x,ll n)
    {
        double res=1;
        while(n) {
            if(n&1)res=res*x;
            x*=x;
            n/=2;
        }
        return res;
    }
public:
    double myPow(double x, int n) {
        ll t=-1LL*n;
    return n>0?Pow(x,(ll)n):Pow(1/x,t);
    }
};

//2^10-->(2^5)*(2^5)-->((2^2)*(2^2)*2)