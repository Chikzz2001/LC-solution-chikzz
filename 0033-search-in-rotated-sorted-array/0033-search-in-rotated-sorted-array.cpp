class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),l=0,r=n-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]>nums[n-1])
                l=m+1;
            else
                r=m-1;
        }
        int pvt=l;
        if(target<=nums[n-1])
        l=pvt,r=n-1;
        else
           l=0,r=pvt-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]==target)return m;
            if(target>nums[m])
                l=m+1;
            else
                r=m-1;
        }
        return -1;
    }
};