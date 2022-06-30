class Solution {
    bool check(vector<int>& nums,int j,vector<int>& v,int n,int m)
    {
        if(m-j<n)return 0;
        for(int i=0;i<n;i++)
        {
            if(nums[j++]!=v[i])
                return 0;
        }
        return 1;
    }
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
     
        int i=0,j=0;
        while(j<nums.size())
        {
            if(nums[j]==groups[i][0])
            {
                if(check(nums,j,groups[i],groups[i].size(),nums.size()))
                {
                    j+=groups[i].size();
                    i++;
                }
                else
                    j++;
            }
            else
                j++;
            if(i==groups.size())return 1;
        }
        return 0;
    }
};