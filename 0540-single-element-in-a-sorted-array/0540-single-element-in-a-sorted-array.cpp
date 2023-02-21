class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(),l=0,h=n-1;
        
        while(l<=h)
        {
            int m=l+(h-l)/2;
            
            if(m&1)
            {
                if(m-1>=0&&nums[m-1]==nums[m])
                    l=m+1;
                else
                    h=m-1;
            }
            else
            {
                if(m-1>=0&&nums[m-1]==nums[m])
                    h=m-2;
                else
                    l=m+2;
            }
        }
        return nums[h];
    }
};