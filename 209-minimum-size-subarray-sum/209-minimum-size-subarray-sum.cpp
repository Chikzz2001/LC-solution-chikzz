class Solution {
    // bool check(vector<int>& nums,int k,int &target)
    // {
    //     for(int i=0;i<=nums.size()-k;i++)
    //     {
    //         int sum=i==0?nums[k-1]:nums[i+k-1]-nums[i-1];
    //         if(sum>=target)
    //             return 1;
    //     }
    //     return 0;
    // }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
//         for(int i=1;i<n;i++)
//             nums[i]+=nums[i-1];
//         int lo=1,hi=n;
//         int ans=0;
//         while(lo<=hi)
//         {
//             int mid=lo+(hi-lo)/2;
            
//             if(check(nums,mid,target))
//             {
//                 ans=mid;
//                 hi=mid-1;
//             }
//             else
//                 lo=mid+1;
//         }
//         return ans;
        long long s=0;
        for(auto &x:nums)s+=x;
        if(s<target)return 0;
        
        int i=0,j=0,res=n;
        long long sum=0;
        while(j<n)
        {
            sum+=nums[j];
            
            while(i<j&&sum-nums[i]>=target)
                sum-=nums[i++];
            
            if(sum>=target)
            res=min(res,j-i+1);
            j++;
        }
        return res;
    }
};