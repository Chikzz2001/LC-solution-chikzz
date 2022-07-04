class Solution {
    vector<int>last_occurence;
    vector<vector<int>>res;
    vector<int>temp;
    void permute(vector<int>& nums,int idx)
    {
        if(idx==nums.size())
        {
            res.push_back(temp);
            return;
        }
        
        int start=last_occurence[nums[idx]+10]+1;
        for(int i=start;i<nums.size();i++)
        {
            if(temp[i]==-11)
            {
                temp[i]=nums[idx];
                last_occurence[nums[idx]+10]=i;
                permute(nums,idx+1);
                temp[i]=-11;
                last_occurence[nums[idx]+10]=start-1;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        last_occurence=vector<int>(21,-1);
        temp=vector<int>(nums.size(),-11);
        permute(nums,0);
        return res;
    }
};