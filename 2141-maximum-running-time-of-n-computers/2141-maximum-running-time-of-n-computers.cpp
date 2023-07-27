#define ll long long
#define min(a,b) a<b?a:b

class Solution {
    bool check(ll mid,vector<int>& batteries,int &n)
    {
        ll mins=0;
        
        //we need to run all computers simultaneously for mid minutes 
        //so for elements greater than mid we can use only run it for mid minutes
        //after than we can not use the left over charge cuz it would fail the case of simultaneous
        //running--->it wd be one after the other
        
        //so for eles<mid take it as they can contri to a pc after one has ended
        //but for ele>mid u hv to take the mid
        for(auto &x:batteries)
        {
            mins+=min(x,mid);
        }
        
        return mins>=n*mid;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        ll lo=0;
        ll hi=0;
        
        for(auto &x:batteries)
        hi+=x;
        
        hi/=n;
        ll res=0;
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            
            //PREDICATE FUNCTION: if we can not run all pcs for mid mins then obviously
            //we can not run all pcs for time>mid mins
            if(check(mid,batteries,n))
            {
                res=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        
        return res;
    }
};
