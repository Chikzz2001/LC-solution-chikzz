class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        int n=nums.size();
        set<vector<int>>S;
        for(int i=3;i<(1<<n);i++)
        {
            if(!(i&(i-1)))continue;
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    if(!temp.size()||temp.back()<=nums[j])
                        temp.push_back(nums[j]);
                }
            }
            if(temp.size()>1)
            S.insert(temp);
        }
        vector<vector<int>>res;
        for(auto &x:S)
            res.push_back(x);
        
        return res;
    }
};