class Solution {
//     int dp[100001];
//     int dfs(vector<int>& nums,int &k,int idx)
//     {
//         if(idx>=nums.size()-1)
//             return nums.back();
        
//         if(dp[idx]!=-1)
//             return dp[idx];
        
//         int maxx=-1e9;
//         for(int j=idx+1;j<=min((int)nums.size()-1,idx+k);j++)
//         {
//             maxx=max(maxx,dfs(nums,k,j));
//         }
        
//         return dp[idx]=nums[idx]+maxx;
//     }
public:
    int maxResult(vector<int>& nums, int k) 
    {
        // memset(dp,-1,sizeof(dp));
        // return dfs(nums,k,0);
        
        int n=nums.size();
        int dp[n];
        dp[0]=nums[0];
        
        deque<int>dQ;
        dQ.push_back(0);
        
        //at every iteration only one push occurs so conversely we can be sure that on popping at most 1 ele
        //we will have the idx at the front of the dQ which can be reached from current idx
        for(int i=1;i<n;i++)
        {
            if(dQ.front()<i-k)
                dQ.pop_front();
            
            dp[i]=nums[i]+dp[dQ.front()];
            
            while(dQ.size()&&dp[dQ.back()]<=dp[i])
                dQ.pop_back();
            
            dQ.push_back(i);
        }
        
        return dp[n-1];
    }
};