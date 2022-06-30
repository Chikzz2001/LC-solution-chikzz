#define ll long long int
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        ll n=nums.size();
        ll pre[n];
        pre[0]=nums[0];
        
        for(int i=1;i<n;i++)
            pre[i]=nums[i]+pre[i-1];
        
        ll minn=1e9;
        
        int res=-1;
        for(ll i=0;i<n-1;i++)
        {
            ll t=abs((pre[i]/(i+1))-((pre[n-1]-pre[i])/(n-i-1)));
            if(t<minn)
            {
                minn=t;
                res=i;
            }
        }
        if(minn>pre[n-1]/n)
            res=n-1;
        return res;
    }
};