#define ll long long int
class Solution {
    bool perfectSquare(ll n)
    {
        if(n==1)return 1;
        ll lo=1,hi=n/2;
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            ll t=1LL*mid*mid;
            if(t==n)
                return 1;
            if(t<n)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return 0;
    }
public:
    bool judgeSquareSum(int c) 
    {
        if(c==0)return 1;
        if(perfectSquare(c))
            return 1;
        for(ll i=1;i*i<=c;i++)
        {
            ll num=c-i*i;
            if(perfectSquare(num))
                return 1;
        }
        return 0;
    }
};