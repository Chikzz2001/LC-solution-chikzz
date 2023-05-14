class Solution {
    vector<vector<int>>dp;
    int N;
    int helper(vector<int>& nums,int mask,int i) {
        if(i==N/2)return 0;
        if(dp[mask][i]!=-1)return dp[mask][i];
        int res=0;
        for(int l=0;l<N;l++) {
            if(mask&(1<<l))continue;
            for(int m=l+1;m<N;m++) {
                if(mask&(1<<m))continue;
                
                res=max(res,(i+1)*(__gcd(nums[l],nums[m]))+helper(nums,mask|(1<<l)|(1<<m),i+1));
            }
        }
        return dp[mask][i]=res;
    }
public:
    int maxScore(vector<int>& nums) {
        N=nums.size();
        dp=vector<vector<int>>(1<<N,vector<int>(N,-1));
        return helper(nums,0,0);
    }
};