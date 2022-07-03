class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        int prev=0;
        vector<int>res;
        for(auto &x:nums)
        {prev+=x;res.push_back(prev);}
        return res;
    }
};