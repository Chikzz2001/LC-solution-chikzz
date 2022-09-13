class Solution {
    vector<vector<int>>res;
    vector<int>temp;
    void helper(vector<int>& nums,int idx)
    {
        res.push_back(temp);
        
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx&&nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            helper(nums,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        helper(nums,0);
        return res;
    }
};