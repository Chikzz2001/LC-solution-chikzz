class Solution {
    int helper(string &s,int i,int prev,vector<vector<int>>& dp)
    {
        if(i==s.length())return 0;
        
        if(dp[i][prev]!=-1)return dp[i][prev];
        
        int minn=1e9;
        if(prev==0)
        {
            if(s[i]=='0')
            {
                //don't filp
                minn=min(minn,helper(s,i+1,0,dp));
                //flip
                minn=min(minn,1+helper(s,i+1,1,dp));
            }
            else
            {
                //flip
                minn=min(minn,1+helper(s,i+1,0,dp));
                //don't flip
                minn=min(minn,helper(s,i+1,1,dp));
            }
        }
        else
        {
            if(s[i]=='0')
            {
                //flip
                minn=min(minn,1+helper(s,i+1,1,dp));
            }
            else
            {
                //don't filp
                minn=min(minn,helper(s,i+1,1,dp));
            }
        }
        return dp[i][prev]=minn;
    }
public:
    int minFlipsMonoIncr(string s) 
    {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(s,0,0,dp);
    }
};