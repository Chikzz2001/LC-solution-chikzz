#define ll long long int
class Solution {
    bool valid(vector<int>& nums,int m)
    {
        if(nums[0]>m)return 0;
        ll excess=m-nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>m)
            {
                if(excess>=(nums[i]-m))
                    excess-=(nums[i]-m);
                else
                    return 0;
            }
            else
                excess+=(m-nums[i]);
        }
       return 1;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int lo=*min_element(nums.begin(),nums.end());
        int hi=*max_element(nums.begin(),nums.end());
        
        int res;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(valid(nums,mid))
            {
                res=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return res;
    }
};