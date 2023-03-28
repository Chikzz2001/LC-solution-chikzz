class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        //dp[j]-->defines min cost to travel in the j days 
    
        int passes[]={1,7,30};
        
        int d_idx=0,n=days.size();
        
        int dp[days[n-1]+1];
        dp[0]=0;
        
        for(int i=1;i<=days[n-1];i++)
        {
            if(days[d_idx]==i)
            {
                dp[i]=costs[0]*(i+1);
                for(int j=0;j<3;j++)
                    dp[i]=min(dp[i],costs[j]+dp[max(0,i-passes[j])]);
                d_idx++;
            }
            else
                dp[i]=dp[i-1];
        }
       
        return dp[days[n-1]];
    }
};

/*
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    2 2 2 4 4 6 7 9 9 9  9  9  9  9  9  9  9  9  9  11
*/