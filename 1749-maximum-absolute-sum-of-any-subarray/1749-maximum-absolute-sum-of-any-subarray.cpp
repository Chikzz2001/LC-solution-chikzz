class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int res=0;
        int curr=nums[0],maxx=nums[0],n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            curr=max(curr+nums[i],nums[i]);
            maxx=max(maxx,curr);
        }
        res=max(res,abs(maxx));
        
        for(auto &x:nums)x*=-1;
        
        curr=nums[0],maxx=nums[0];
        for(int i=1;i<n;i++)
        {
            curr=max(curr+nums[i],nums[i]);
            maxx=max(maxx,curr);
        }
        res=max(res,abs(maxx));
        
        return res;
    }
};