class Solution {
//     int K,N;
//     int dp[501];
//     int helper(vector<int>& arr,int i)
//     {
//         if(i>=N)return 0;
        
//         if(dp[i]!=-1)
//             return dp[i];
        
//         int maxx=0;
//         int res=0;
//         for(int j=i;j<min(N,i+K);j++)
//         {
//             maxx=max(maxx,arr[j]);
//             int sum=(j-i+1)*maxx;
//             res=max(res,sum+helper(arr,j+1));
//         }
//         return dp[i]=res;
//     }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        // memset(dp,-1,sizeof(dp));
        // K=k;
        // N=arr.size();
        // helper(arr,0);
        // return dp[0];
        
        int n=arr.size();
        int dp[n];
        
        //dp[i]-->define maximum possible sum from 0 to i
        
        fill(dp,dp+n,0);
        
        dp[0]=arr[0];
        
        for(int i=1;i<n;i++)
        {
            int maxx=0;
            for(int j=i;j>=max(0,i-k+1);j--)
            {
                maxx=max(maxx,arr[j]);
                int l=j>0?dp[j-1]:0;
                int r=(i-j+1)*maxx;
                dp[i]=max(dp[i],l+r);
            }
        }
        return dp[n-1];
    }
};
