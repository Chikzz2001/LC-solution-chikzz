class Solution {
    vector<vector<int>>dp;
    int helper(vector<int>& nums,vector<int>& multipliers,int s,int e,int i)
    {
        if(i==multipliers.size())return 0;
        
        // string key=to_string(s)+"#"+to_string(e)+"#"+to_string(i);
        // if(dp.count(key))return dp[key];
        if(dp[s][i]!=-1e9)return dp[s][i];
        int op1=nums[s]*multipliers[i]+helper(nums,multipliers,s+1,e,i+1);
        int op2=nums[e]*multipliers[i]+helper(nums,multipliers,s,e-1,i+1);
        return dp[s][i]=max(op1,op2);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        //memset(dp,-1,sizeof(dp));
        int m=multipliers.size();
        dp=vector<vector<int>>(m+1,vector<int>(m+1,-1e9));
        return helper(nums,multipliers,0,nums.size()-1,0);
    }
};