#define ll long long
class Solution {
    const int M=1e9+7;
    ll binexp(int a,int p) {
        if(p==0)return 1;
        if(a%M==0)return 0;
        ll res=binexp(a,p/2);
        if(p&1) {
            return ((a*res%M)%M*res%M)%M;
        }
        return (res%M*res%M)%M;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        ll res=0;
        
        for(int x:nums) {
            
        }
        
        for(int i=0;i<n;i++) {
            if(nums[i]*2<=target)res=(res+1)%M;
            else break;
            int idx=upper_bound(nums.begin()+i,nums.end(),target-nums[i])-nums.begin()-1;
            if(idx==i)continue;
            
            int sz=idx-i;
            ll c=binexp(2,sz);
            // cout<<i<<" "<<idx<<" "<<c<<"\n";
            res=(res+c%M-1+M)%M;
        }
        return res;
    }
};
/*
3 5 6 7
3 6-->2^2-2=2
3 5-->2^1-2=0

2^sz-2+2^(sz+1)-2...

nums[i]+nums[j]<=target
i<nums[j]<=target-nums[i]
*/