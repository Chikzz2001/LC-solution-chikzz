class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long res=0;
        int n=nums.size();
        vector<int>suf(n);
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)suf[i]=suf[i+1]|nums[i];
        int p=0;
        for(int i=0;i<n;i++) {
            long long curr=nums[i];
            curr<<=(1ll*k);
            res=max(res,curr|p|(i<n-1?suf[i+1]:0));
            p|=nums[i];
        }
        return res;
    }
};