#define ll long long
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        int n=nums.size();
        
        if(n<2)return 0;
        if(t==0)
        {
            unordered_set<int>s;
            for(auto &x:nums)
                s.insert(x);
            
            if(s.size()==n)return 0;
        }
                
        set<ll>S;
        for(int i=0;i<n;i++)
        {
            if(i>k)
                S.erase(1LL*nums[i-k-1]);
            
            auto lo=S.lower_bound(1LL*nums[i]-t);
            
            if(lo!=S.end()&&*lo-t<=1LL*nums[i])
                return 1;
            
            S.insert(1LL*nums[i]);
        }
        
        return 0;
    }
};
