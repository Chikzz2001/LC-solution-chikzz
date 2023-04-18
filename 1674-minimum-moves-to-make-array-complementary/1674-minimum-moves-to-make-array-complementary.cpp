class Solution {
    int dp[200100];
public:
    int minMoves(vector<int>& nums, int l) {
        int n=nums.size();
        for(int i=0;i<n/2;i++) {
            int a=nums[i],b=nums[n-i-1];
            dp[2]+=2;
            dp[min(a+1,b+1)]--;
            dp[a+b]--;
            dp[a+b+1]++;
            dp[max(a+l,b+l)+1]++;
            dp[2*l+1]-=2;
        }
        int pre=0,res=1e9;
        for(int i=2;i<=2*l;i++) {
            pre+=dp[i];
            res=min(res,pre);
        }
        return res;
    }
};

/*
1+1 a+1 1+b a+l l+b l+l
*/