#define ll long long int
class Solution {
    int mCount(vector<int>& nums,int t)
    {
        int res=0;
        for(auto &x:nums)
            res+=abs(t-x);
        return res;
    }
public:
    int minMoves2(vector<int>& nums) 
    {
      sort(nums.begin(),nums.end());
        int n=nums.size();
        
        if(n&1)
            return mCount(nums,nums[n/2]);
        return min(mCount(nums,nums[n/2]),mCount(nums,nums[n/2-1]));
    }
};

/*

1 0 0 8 6
0 1 1 7 5
3*x-1+8-x+6-x=14==>x=13

1 2 9 10
4 3 4 5
*/