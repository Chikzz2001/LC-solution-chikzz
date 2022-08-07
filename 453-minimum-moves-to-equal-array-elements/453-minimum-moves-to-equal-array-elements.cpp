class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        if(nums.size()==1)return 0;
        
        sort(nums.begin(),nums.end());
        int steps=0,n=nums.size();
        for(int i=n-2;i>=0;i--)
        {
            steps+=(nums[i+1]-nums[i])*(n-i-1);
        }
        return steps;
    }
};