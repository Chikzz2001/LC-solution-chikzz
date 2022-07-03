class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        long long sum=0;
        for(auto &x:nums)
            sum+=x;
        
        long long sum1=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum1==sum-(sum1+nums[i]))
                return i;
            sum1+=nums[i];
        }
        return -1;
    }
};