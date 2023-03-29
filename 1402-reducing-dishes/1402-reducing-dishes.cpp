#define ll long long int
class Solution {
//     ll dp[501][502];
//     ll helper(vector<int>& satisfaction,int idx,int time)
//     {
//         if(idx==satisfaction.size())
//         {
//             return 0;
//         }
        
//         if(dp[idx][time]!=-1)
//             return dp[idx][time];
        
//         ll do_job=-1e12,dont_do_job=-1e12;

//         //do the job
//         do_job=satisfaction[idx]*(time)+helper(satisfaction,idx+1,time+1);
//         //don't do job
//         dont_do_job=helper(satisfaction,idx+1,time);
        
//         return dp[idx][time]=max(do_job,dont_do_job);
//     }
public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        int n=satisfaction.size();
        
        sort(satisfaction.begin(),satisfaction.end());
        // memset(dp,-1,sizeof(dp));
        // return helper(satisfaction,0,1);
        ll dp[n+1][n+1];
        
        for(int i=0;i<=n;i++)
        dp[n][i]=0,dp[i][n]=0;
        
        for(int i=n-1;i>=0;i--)
            for(int j=n-1;j>=0;j--)
                dp[i][j]=max(dp[i+1][j],satisfaction[i]*(j+1)+dp[i+1][j+1]);
        
        return dp[0][0];
    }
};