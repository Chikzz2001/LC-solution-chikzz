class Solution {
    int dp[101][101];
    int mincost(int s,int e,vector<int>& cuts)
    {
        if(s>e)
            return 0;
        
        if(dp[s][e]!=-1)
            return dp[s][e];
        
        int minn=1e9;
        
        int Cost=cuts[e+1]-cuts[s-1];
        
        for(int i=s;i<=e;i++)
        {
            int left=mincost(s,i-1,cuts);
            int right=mincost(i+1,e,cuts);
            minn=min(minn,left+Cost+right);
        }
        
        return dp[s][e]=minn;
    }
public:
    int minCost(int n, vector<int>& cuts) 
    {
        cuts.push_back(0);
        cuts.push_back(n);
        int len=cuts.size();
        
        sort(cuts.begin(),cuts.end());
        
        memset(dp,-1,sizeof(dp));
        return mincost(1,len-2,cuts);
    }
};
//0 1 3 4 5 7
//    |       -->7(7-0)
//        |   -->4(7-3)
//  |         -->3(3-0)
//      |     -->2(5-3)