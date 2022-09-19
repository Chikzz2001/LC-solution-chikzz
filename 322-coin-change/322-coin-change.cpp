class Solution {
    int dp[12][10001];
    int minNoOfCoins(vector<int>& coins,int amount,int index)
    {
        if(index==coins.size())
        {
            return amount?1e7:0;
        }
        
        if(!amount)return 0;
        
        if(dp[index][amount]!=-1)return dp[index][amount];
        
        int take=1e7,non_take=1e7;
        //do not take the current coin under consideration
        non_take=minNoOfCoins(coins,amount,index+1);
        //do take the current coin under consideration if possible
        if(amount-coins[index]>=0)
            take=1+minNoOfCoins(coins,amount-coins[index],index);
        return dp[index][amount]=min(take,non_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp,-1,sizeof(dp));
        int res=minNoOfCoins(coins,amount,0);
        return res>=1e7?-1:res;
    }
};