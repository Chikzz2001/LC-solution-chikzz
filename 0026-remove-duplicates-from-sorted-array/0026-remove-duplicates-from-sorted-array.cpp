class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=0,j=0,n=nums.size();
        
        while(i<n)
        {
            nums[j]=nums[i];
            j++;
            while(i<n&&nums[i]==nums[j-1])
                i++;
        }
        return j;
    }
};