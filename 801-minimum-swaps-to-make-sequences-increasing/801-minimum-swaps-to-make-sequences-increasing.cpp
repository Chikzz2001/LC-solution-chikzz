class Solution 
{
   int minSwaps(vector<int>& nums1,vector<int>& nums2,int i,vector<vector<int>>& dp)
   {
       if(i==nums1.size())
           return 0;
       
       if(dp[i][0]!=1e9&&dp[i][1]!=1e9)
           return min(dp[i][0],dp[i][1]);
       
       int res=1e9;
       if(nums1[i]>nums1[i-1]&&nums2[i]>nums2[i-1])
       {
            res=minSwaps(nums1,nums2,i+1,dp);
       }
       
       dp[i][0]=res;
     
       if(nums2[i]>nums1[i-1]&&nums1[i]>nums2[i-1])
       {
           swap(nums1[i],nums2[i]);
           int res2=minSwaps(nums1,nums2,i+1,dp);
           res=min(res,1+res2);
           dp[i][1]=1+res2;
           swap(nums1[i],nums2[i]); 
       }
       
       return res;
   }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
       vector<vector<int>>dp(n+1,vector<int>(2,1e9));
        int res=1e9;
        
         res=minSwaps(nums1,nums2,1,dp);  
         swap(nums1[0],nums2[0]);
         res=min(res,1+minSwaps(nums1,nums2,1,dp));  

        return res;
    }
};