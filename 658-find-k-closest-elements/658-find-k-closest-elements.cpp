class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<int>res;
        int n=arr.size();
        if(x<=arr[0])
        {
            for(int i=0;i<min(n,k);i++)
                res.push_back(arr[i]);
            return res;
        }
        
        if(x>arr[n-1])
        {
            for(int i=n-1;i>=max(0,n-k);i--)
                res.push_back(arr[i]);
            reverse(res.begin(),res.end());
            return res;
        }
        
        int idx=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int lo,hi;
        if(arr[idx]==x)
        {
            res.push_back(x);
            lo=idx-1,hi=idx+1;
            k--;
        }
        else
        lo=idx-1,hi=idx;
        //cout<<k<<"\n";
        while(lo>=0&&hi<n&&k-->0)
        {
            if(x-arr[lo]<=arr[hi]-x)
            {
                res.push_back(arr[lo--]);
            }
            else
            {
                res.push_back(arr[hi++]);
            }
        }
           //cout<<k<<"\n";
        while(lo>=0&&k-->0)
        {
            res.push_back(arr[lo--]);
        }
        //cout<<k<<" "<<lo<<" "<<hi<<"\n";
         while(hi<n&&k-->0)
        {
            res.push_back(arr[hi++]);
        }
        sort(res.begin(),res.end());
        return res;
    }
};