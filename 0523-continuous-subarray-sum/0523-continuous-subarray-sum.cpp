class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // vector<int>v(k,-2);
        // int sum=0;
        // v[0]=-1;
        // int rem;
        // for(int i=0;i<nums.size();i++)
        // {
        //     sum+=nums[i];
        //     rem=sum%k;
        //     if(rem<0)rem+=k;
        //     if(v[rem]!=-2&&(i-v[rem]>=2))return 1;
        //     if(v[rem]==-2)v[rem]=i;
        // }
        // return 0;
        
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;
        int rem;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            rem=sum%k;
            if(rem<0)rem+=k;
            if(mp.find(rem)!=mp.end()&&(i-mp[rem]>=2))return 1;
            if(mp.find(rem)==mp.end())mp[rem]=i;
        }
        return 0;
    }
};