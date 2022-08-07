class Solution {
public:
    bool validPartition(vector<int>& nums) 
    {
        int n=nums.size();
        bool dp[n+1];
        dp[0]=1,dp[1]=0,dp[2]=nums[1]==nums[0]?1:0;
        for(int i=2;i<n;i++)
        {
            dp[i+1]=0;
            if(nums[i]==nums[i-1])
                dp[i+1]|=dp[i-1];
            if(i>=2&&nums[i]==nums[i-1]&&nums[i-1]==nums[i-2])
                dp[i+1]|=dp[i-2];
            if(i>=2&&nums[i]-nums[i-1]==1&&nums[i-1]-nums[i-2]==1)
                dp[i+1]|=dp[i-2];
        }
        
        // for(int i=1;i<=n;i++)
        //     cout<<(dp[i]?"true ":"false ");
        return dp[n];
    }
};


/*

[803201,803201,803201,803201,803202,803203]

*/