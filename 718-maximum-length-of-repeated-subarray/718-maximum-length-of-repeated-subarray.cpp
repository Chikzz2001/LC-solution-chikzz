class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size(),m=nums2.size();
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;
        
        int res=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=0;
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
};