#define ll long long int
int sumofdigits(ll n)
{
    int sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        //n=17
        //17-->1+6+6+5
        //move from right and keep on doin round-off
        int c=1;
        ll temp=n;
        while(1)
        {
            if(sumofdigits(n)<=target)
                return n-temp;
            double t=ceil(n*1.0/pow(10,c));
            t*=pow(10,c);
            n=(ll)t;
            c++;
        }
        return n-temp;
    }
};