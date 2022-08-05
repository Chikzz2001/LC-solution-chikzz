class Solution {
    int dp[1001];
    int help(vector<int>& nums,int amt,int &n)
    {
        if(amt<0)return 0;
        if(amt==0)return 1;
        if(dp[amt]!=-1)return dp[amt];
        int sum=0;
        for(int i=0;i<n;i++)
        {
          sum+=help(nums,amt-nums[i],n);  
        }
        return dp[amt]=sum;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return help(nums,target,n);
        // vector<int>dp(target+1,0);
        // dp[0]=1;
        // for(int i=1;i<=target;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if((i-nums[j])>=0)
        //             dp[i]+=dp[i-nums[j]];
        //     }
        // }
        // return dp[target];
    }
};


