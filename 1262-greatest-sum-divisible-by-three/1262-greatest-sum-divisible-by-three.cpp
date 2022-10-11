class Solution {
     int dp[40001][3];
public:
    int maxSumDivThree(vector<int>& nums) 
    {
       dp[0][nums[0]%3]=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            int rem=nums[i]%3;
            if(rem==0)
            {
                dp[i][0]=dp[i-1][0]+nums[i];
                if(dp[i-1][1])
                dp[i][1]=dp[i-1][1]+nums[i];
                if(dp[i-1][2])
                dp[i][2]=dp[i-1][2]+nums[i];
            }
            else if(rem==1)
            {
                if(dp[i-1][2])
                dp[i][0]=max(dp[i-1][0],dp[i-1][2]+nums[i]);
                else
                    dp[i][0]=dp[i-1][0];
                dp[i][1]=max(dp[i-1][1],dp[i-1][0]+nums[i]);
                if(dp[i-1][1])
                dp[i][2]=max(dp[i-1][2],dp[i-1][1]+nums[i]);
                else
                    dp[i][2]=dp[i-1][2];
            }
            else
            {
                if(dp[i-1][1])
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+nums[i]);
                else
                     dp[i][0]=dp[i-1][0];
                if(dp[i-1][2])
                dp[i][1]=max(dp[i-1][1],dp[i-1][2]+nums[i]);
                else
                    dp[i][1]=dp[i-1][1];
                dp[i][2]=max(dp[i-1][2],dp[i-1][0]+nums[i]);
            }
        }
        
        // for(int i=0;i<3;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<dp[j][i]<<" ";
        //     cout<<"\n";
        // }
        return dp[n-1][0];
    }
};

/*

    3 6 5 1 8
0   3 9 9 15 18
1   0 0 0 10 22
2   0 0 14 14

*/


/*

[3,6,5,1,8]
[4]
[1,2,3,4,4]
[7,3,7,4,2,2,7,5]
[4,1,5,3,1]

*/
