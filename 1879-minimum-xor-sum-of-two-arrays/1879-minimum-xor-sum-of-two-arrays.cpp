class Solution {
    int dp[1<<15][15];
    int helper(vector<int>& nums1,vector<int>& nums2,int mask,int i)
    {
        if(i==nums1.size())
        {
            return 0;
        }
        
        if(dp[mask][i]!=-1)return dp[mask][i];
        
        int minn=1e9;
        for(int j=0;j<nums2.size();j++)
        {
            if(!((mask>>j)&1))
            {
                minn=min(minn,(nums1[i]^nums2[j])+helper(nums1,nums2,mask|(1<<j),i+1));
            }
        }
        return dp[mask][i]=minn;
    }
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return helper(nums1,nums2,0,0);
    }
};