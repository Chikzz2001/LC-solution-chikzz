class Solution {
    struct node
    {
        int start,end,profit;
        node(int _start,int _end,int _profit)
        {
            start=_start;
            end=_end;
            profit=_profit;
        }
    };
    
    int UpperBound(vector<node>& jobs,int val)
    {
        int lo=0,hi=jobs.size()-1;
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(jobs[mid].end<=val)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return lo;
    }
//     int maxProfit(vector<node>& jobs,int i,int prev,int &n,vector<vector<int>>& dp)
//     {
//         if(i==n)
//             return 0;
        
//         if(dp[i][prev]!=-1)return dp[i][prev];
        
//         int take=0,non_take=0;
//         if(jobs[i].start>=prev)
//         {
//             take=jobs[i].profit+maxProfit(jobs,i+1,jobs[i].end,n,dp);
//         }
//         non_take=maxProfit(jobs,i+1,prev,n,dp);
        
//         return dp[i][prev]=max(take,non_take);
//     }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        vector<node>jobs;
        int n=startTime.size();
        int max_endtime=0;
        for(int i=0;i<n;i++)
        {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
            max_endtime=max(max_endtime,endTime[i]);
        }
        
        sort(jobs.begin(),jobs.end(),[&](const node& j1,const node& j2)
             {
                 //return j1.start<j2.start;
                 return j1.end<j2.end;
             });
        
        // vector<vector<int>>dp(n,vector<int>(max_endtime+1,-1));
        // return maxProfit(jobs,0,1,n,dp);
        
        int dp[n];
        dp[0]=jobs[0].profit;
        
        for(int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1],jobs[i].profit);
            // for(int j=i-1;j>=0;j--)
            // {
            //     if(jobs[j].end<=jobs[i].start)
            //     {
            //         dp[i]=max(dp[i],jobs[i].profit+dp[j]);
            //         break;
            //     }
            // }
            int idx=UpperBound(jobs,jobs[i].start)-1;
            if(idx!=-1)
                dp[i]=max(dp[i],jobs[i].profit+dp[idx]);
        }
        return dp[n-1];
    }
};