#define ll long long int
class Solution {
    const int M=1e9+7;
public:
    int countVowelPermutation(int n) {
        ll pa=1,pe=1,pi=1,po=1,pu=1;
        
        for(int c=1;c<n;c++)
        {
                ll a=pe;
                ll e=(pa+pi)%M;
                ll i=((pa+pe)%M+(po+pu)%M)%M;
                ll o=(pi+pu)%M;
                ll u=pa;
                pa=a,pe=e,pi=i,po=o,pu=u;
        }
        
        ll res=0;
            res=(pa%M+pe%M+pi%M+po%M+pu%M)%M;
        
        return res;
    }
};