class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            max_reach=max(max_reach,i+nums[i]);
            if(max_reach>=n-1)return 1;
            if(max_reach<=i)
                return 0;
        }
        return 1;
    }
};