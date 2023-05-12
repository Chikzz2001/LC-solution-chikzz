class Solution {
    int pre[1005],suff[1005],num[1005];
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n=nums.size();
        num[0]=-1e5,num[n+1]=1e5;
        for(int i=1;i<=n;i++)num[i]=nums[i-1];
        pre[0]=1,pre[1]=1,suff[n+1]=1,suff[n]=1;
        for(int i=2;i<=n;i++) {
            if(num[i]>num[i-1])pre[i]=1;
            else break;
        }
        for(int i=n-1;i>=1;i--) {
            if(num[i]<num[i+1])suff[i]=1;
            else break;
        }
        
        if(pre[n]==1)return 1;
        for(int i=1;i<=n;i++) {
            if(pre[i-1]&&suff[i+1]&&num[i-1]<num[i+1])return 1;
        }
        return 0;
    }
};