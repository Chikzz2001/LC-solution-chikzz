// class Solution {
// public:
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size(),m=nums2.size();
//         int dp[n][m];
//         int ma=INT_MIN;
//         for(int i=0;i<n;i++){
//             dp[i][0]=(nums1[i]==nums2[0])?1:0;
//             ma=max(ma,dp[i][0]);} 
//         for(int i=0;i<m;i++)
//         {dp[0][i]=(nums1[0]==nums2[i])?1:0;
//         ma=max(ma,dp[0][i]);}
//         for(int i=1;i<n;i++)
//         {
//             for(int j=1;j<m;j++)
//             {
//                 if(nums1[i]==nums2[j])dp[i][j]=1+dp[i-1][j-1];
//                 else
//                     dp[i][j]=0;
//                 ma=max(ma,dp[i][j]);
//             }
//         }
//         return ma;
//     }
// };

class Solution {
    int maxsublen_of_first_in_second(vector<int>& nums1,vector<int>& nums2)
    {
        int n=nums1.size(),m=nums2.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;)
            {
                if(nums1[i]==nums2[j])
                {
                    int k=i;
                    int len=0;
                    while(j<m&&k<n&&nums1[k]==nums2[j])
                        j++,k++,len++;
                    if(len>res)
                    {
                        res=max(res,len);
                    }
                    
                }
                else
                    j++;
            }
        }
        return res;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return max(maxsublen_of_first_in_second(nums1,nums2),maxsublen_of_first_in_second(nums2,nums1));
    }
};
