class Solution {
    vector<int>T;
    int K,N;
    int helper(vector<int>& nums,int i) {
        if(i==N) {
            return T.size()?1:0;
        }
        
        int idx=lower_bound(T.begin(),T.end(),nums[i]-K)-T.begin();
        int res=0;
        if(idx<T.size()&&T[idx]==nums[i]-K) {
            
        }else {
            T.push_back(nums[i]);
            res+=helper(nums,i+1);
            T.pop_back();
        }
        res+=helper(nums,i+1);
        return res;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        K=k,N=nums.size();
        sort(nums.begin(),nums.end());
        return helper(nums,0);
    }
};