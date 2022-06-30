#define ll long long int
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        int n=nums.size();

        ll pos=-1e6,neg=0;
        
        for(int i=1;i<=n;i++)
        {
            ll tpos=max(pos,neg+nums[i-1]);
            ll tneg=max(neg,pos-nums[i-1]);
            pos=tpos,neg=tneg;
        }
        
        return max(pos,neg);
    }
};