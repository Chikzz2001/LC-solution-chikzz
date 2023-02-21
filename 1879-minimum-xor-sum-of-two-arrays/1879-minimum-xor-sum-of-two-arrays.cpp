class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>dp((1<<n),0);
        for(int i=n-1;i>=0;i--) {
            vector<int>t_dp((1<<n),1e9);
            for(int j=0;j<(1<<n);j++) {
                for(int k=0;k<n;k++) {
                    if(!(j&(1<<k)))
                    t_dp[j]=min(t_dp[j],(nums1[i]^nums2[k])+dp[j|(1<<k)]);
                }
            }
            dp=t_dp;
        }
        return dp[0];
    }
};


//11111111111111-->2
