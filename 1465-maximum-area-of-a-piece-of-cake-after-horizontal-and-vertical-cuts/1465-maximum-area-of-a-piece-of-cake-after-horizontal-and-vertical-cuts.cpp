#define ll long long int
class Solution {
    const int M=1e9+7;
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC)
    {
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        ll max1=0,max2=0;
        
        for(int i=1;i<hC.size();i++)
            max1=max(max1,1LL*hC[i]-1LL*hC[i-1]);
        
        max1=max({max1,1LL*hC[0],1LL*h-1LL*hC.back()});
        
        for(int i=1;i<vC.size();i++)
            max2=max(max2,1LL*vC[i]-1LL*vC[i-1]);
        
        max2=max({max2,1LL*vC[0],1LL*w-1LL*vC.back()});
        
        ll res=(max1%M*max2%M)%M;
        return res;
    }
};