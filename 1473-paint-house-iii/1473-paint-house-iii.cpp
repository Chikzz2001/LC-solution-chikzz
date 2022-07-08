class Solution {
    vector<vector<vector<int>>>dp;
    int helper(vector<int>& houses,vector<vector<int>>& cost,int m,int n,int target,int idx,int prev)
    {
        if(target<0)return 1e9;
        if(idx==m)
            return target==0?0:1e9;
        
        if(prev!=-1&&dp[idx][target][prev]!=-1)
            return dp[idx][target][prev];
        
        if(houses[idx]!=0)
        {
            if(houses[idx]==prev)
            {
                return dp[idx][target][prev]=helper(houses,cost,m,n,target,idx+1,prev);
            }
            else
            {
                if(prev==-1)
                return helper(houses,cost,m,n,target-1,idx+1,houses[idx]);
                else
                    return dp[idx][target][prev]=helper(houses,cost,m,n,target-1,idx+1,houses[idx]);
            }
        }
        else
        {
            int minn=1e9;
            if(prev!=-1)
            minn=cost[idx][prev-1]+helper(houses,cost,m,n,target,idx+1,prev);
            for(int i=1;i<=n;i++)
            {
                if(i==prev)continue;
                minn=min(minn,cost[idx][i-1]+helper(houses,cost,m,n,target-1,idx+1,i));
            }
            if(prev!=-1)
            return dp[idx][target][prev]=minn;
            else
                return minn;
        }
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        dp=vector<vector<vector<int>>>(m,vector<vector<int>>(target+1,vector<int>(n+1,-1)));
        int res=helper(houses,cost,m,n,target,0,-1);
        return res>=1e9?-1:res;
    }
};