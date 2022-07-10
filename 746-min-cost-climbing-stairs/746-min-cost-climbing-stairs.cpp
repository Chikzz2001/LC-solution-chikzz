class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        int dp[n];
        
        //dp[i]-->represents min cost to reach from i to top floor
        
        dp[n-1]=cost[n-1];
        dp[n-2]=cost[n-2];
        
        for(int i=n-3;i>=0;i--)
        {
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        
        return min(dp[0],dp[1]);
    }
};

//1 100 1 1 1 100 1 1 100 1
//6 105 5 5 4 102 3 2 100 1