class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //a+b>c a+c>b b+c>a
        int n=nums.size();
        for(int i=n-3;i>=0;i--)
        {
            if(nums[i]+nums[i+1]>nums[i+2])
            {
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return 0;
    }
};

//[3,6,2,3]
//2 3 3 6
//