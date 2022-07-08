class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        //dp[i][j]-->define max length of arithmatic seq till ith idx with common diff as j
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(1002,1));
        int res=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                dp[i][nums[i]-nums[j]+500]=max(dp[i][nums[i]-nums[j]+500],1+dp[j][nums[i]-nums[j]+500]);
                res=max(res,dp[i][nums[i]-nums[j]+500]);
            }
        }
        return res;
    }
};

/*

20 1 15 3 10 5 8
1  2 2  

*/