#define ll long long
class Solution {
    ll dp[1001][1<<11];
    map<int,int>prime;
    const int M=1e9+7;
    ll msk[1001];
    ll helper(vector<int>& nums,int i,int mask) {
        
        if(i==nums.size()) {
            return 1;
        }
        
        if(dp[i][mask]!=-1)return dp[i][mask];
        
        ll res=0;

        res=helper(nums,i+1,mask);
        
        if(msk[i]!=-1&&(mask&msk[i])==0)
            res=(res%M+helper(nums,i+1,mask|msk[i])%M)%M;
        
            return dp[i][mask]=res;
    }
public:
    int squareFreeSubsets(vector<int>& nums) {
        int a[]={2,3,5,7,11,13,17,19,23,29};
        for(int i=0;i<10;i++) {
            prime[a[i]]=i;
        }
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<nums.size();i++) {
            int t_mask=0;
            for(int j=0;j<10;j++) {
                int c=0,x=nums[i];
                while(x%a[j]==0) {
                    c++;
                    x/=a[j];
                }
                if(c>1){msk[i]=-1;break;}
                if(c==1)t_mask|=(1<<j);
            }
            if(msk[i]==-1)continue;
            msk[i]=t_mask;
        }
        ll res=helper(nums,0,0);
        res=(res-1+M)%M;
        return res;
    }
};

/*

   3 4 4 5
 2 0 2 2 0
 3 1 0 0 0
 5 0 0 0 1
 
   0 0 0 
   1 1 1
   0 1 1 
*/