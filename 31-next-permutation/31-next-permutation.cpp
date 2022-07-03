class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int turnpoint=-1;
        
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                turnpoint=i-1;
                break;
            }
        }
        
        if(turnpoint==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[turnpoint])
            {
                swap(nums[i],nums[turnpoint]);
                reverse(nums.begin()+turnpoint+1,nums.end());
                return;
            }
        }
    }
};