class Solution {
    int mCount(vector<int>& nums,int t)
    {
        int res=0;
        for(auto &x:nums)
            res+=abs(t-x);
        return res;
    }
public:
    int minMoves2(vector<int>& nums) 
    {
      sort(nums.begin(),nums.end());
        int n=nums.size();
        
        if(n&1)
            return mCount(nums,nums[n/2]);
        return min(mCount(nums,nums[n/2]),mCount(nums,nums[n/2-1]));
    }
};

