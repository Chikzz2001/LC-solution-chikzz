#define ll long long int
class Solution {
    ll dp[100001][2];
    ll helper(vector<int>& nums,int op,int i)
    {
        if(i==nums.size())
            return 0;
        
        if(dp[i][op]!=-1)
            return dp[i][op];
        
        ll maxx=helper(nums,op,i+1);
        if(op)
        {
            maxx=max(maxx,-nums[i]+helper(nums,0,i+1));
        }
        else
        {
            maxx=max(maxx,nums[i]+helper(nums,1,i+1));
        }
        return dp[i][op]=maxx;
    }
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        //max-min
        /*
        
            7 2 3 9 1 6
            dp[i][0]-->add
            dp[i][1]-->sub
            
        */
        
        memset(dp,-1LL,sizeof(dp));
        return helper(nums,0,0);
    }
};