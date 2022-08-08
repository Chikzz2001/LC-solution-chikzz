class Solution {
    int bs(vector<int>& nums,int ele)
    {
        int lo=0,hi=nums.size()-1;
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=ele)
                hi=mid-1;
            else
                lo=mid+1;
        }
        
        return lo;
    }
    //1 1 2 2 3
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int>LIS;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(!LIS.size()||LIS.back()<nums[i])
                LIS.push_back(nums[i]);
            else
            {
                int idx=bs(LIS,nums[i]);
                LIS[idx]=nums[i];
            }
        }
        
        return LIS.size();
    }
};