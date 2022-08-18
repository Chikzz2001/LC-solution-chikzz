class Solution {
    vector<vector<vector<int>>>dp;
    int helper(vector<int>& prices,int i,int k,int buy)
    {
        if(i==prices.size()||!k)
        {
            return 0;
        }
        
        if(dp[i][k][buy]!=-1)
            return dp[i][k][buy];
        
        int res=0;
        if(buy)
        {
            //skip
            res=max(res,helper(prices,i+1,k,1));
            //buy
            res=max(res,-prices[i]+helper(prices,i+1,k,0));
        }
        else
        {
            //skip
            res=max(res,helper(prices,i+1,k,0));
            //sell
            res=max(res,prices[i]+helper(prices,i+1,k-1,1));
        }
        return dp[i][k][buy]=res;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        dp=vector<vector<vector<int>>>(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return helper(prices,0,k,1);
    }
};