class Solution {
    int countPairs(vector<int>& nums,int mid)
    {
        //1 1 3
        //d-a=mid
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            int idx=upper_bound(nums.begin(),nums.end(),nums[i]+mid)-nums.begin();
            idx--;
            res+=(idx-i);
        }
        return res;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int lo=1e9,hi=nums[n-1]-nums[0];
        for(int i=1;i<n;i++)lo=min(lo,nums[i]-nums[i-1]);
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            int noOfPairs=countPairs(nums,mid);
            if(noOfPairs>=k)
            {
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return lo;
    }
};