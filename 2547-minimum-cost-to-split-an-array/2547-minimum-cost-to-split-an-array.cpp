#define ll long long int
#define min(a,b) a<b?a:b
class Solution {
    int K,N,maxx;
    ll helper(vector<int>& nums,int idx,vector<ll>& dp)
    {
        if(idx==N)return 0;
        if(dp[idx]!=-1)return dp[idx];
        vector<int>m(maxx+1,0);
        ll minn=1e12;
        int t=0;
        for(int i=idx;i<N;i++)
        {
            if(m[nums[i]])
            {if(m[nums[i]]==1)t--;}
            else t++;
            m[nums[i]]++;
            ll a=helper(nums,i+1,dp);
                minn=min(minn,K+(i-idx+1)-t+a); 
        }
        return dp[idx]=minn;
    }
public:
    int minCost(vector<int>& nums, int k) {
        K=k,N=nums.size();
        maxx=*max_element(nums.begin(),nums.end());
        vector<ll>dp(N,-1);
        return helper(nums,0,dp);
    }
};