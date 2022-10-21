class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(n==1)return 0;
        
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(i-k>0)
            {
                mp[nums[i-k-1]]--;
                if(mp[nums[i-k-1]]==0)mp.erase(nums[i-k-1]);
            }
            
            if(mp.count(nums[i]))
                return 1;
            
            mp[nums[i]]++;
        }
        
        return 0;
    }
};