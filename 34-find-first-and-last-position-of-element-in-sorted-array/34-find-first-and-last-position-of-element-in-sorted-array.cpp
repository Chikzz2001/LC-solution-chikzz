class Solution {
    int Lower_bound(vector<int>& nums,int val)
    {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=val)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return lo;
    }
    int Upper_bound(vector<int>& nums,int val)
    {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<=val)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return lo;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(!nums.size())return {-1,-1};
        int idx1=Lower_bound(nums,target);
        int idx2=Upper_bound(nums,target)-1;
        vector<int>res(2,-1);
        if(idx1!=nums.size()&&nums[idx1]==target)res[0]=idx1,res[1]=idx2;
        return res;
    }
};