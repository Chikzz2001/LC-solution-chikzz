class Solution {
public:
    int trap(vector<int>& nums) 
    {
       int n=nums.size();
    if(!n)return 0;
    int lmax=nums[0],rmax=nums[n-1],l=0,r=n-1;
    int res=0;
    while(l<=r)
    {
        lmax=max(lmax,nums[l]);
        rmax=max(rmax,nums[r]);
        if(lmax>rmax)
        {
            res+=rmax-nums[r];
            r--;
        }
        else
        {
            res+=lmax-nums[l];
            l++;
        }
    }
    return res;
    }
};