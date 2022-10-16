class Solution {
    int N;
    int dp[301][11];
    int premax[301];
    int helper(vector<int>& jobDifficulty,int start,int d)
    {
        if(d==1)
        {
            return premax[start];
        }
        
        if(dp[start][d]!=-1)return dp[start][d];
        
        int maxx=0,res=1e9;
        for(int i=start;i<N-d+1;i++)
        {
            maxx=max(maxx,jobDifficulty[i]);
            res=min(res,maxx+helper(jobDifficulty,i+1,d-1));
        }
        return dp[start][d]=res;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        N=jobDifficulty.size();
        if(N<d)return -1;
        
        memset(dp,-1,sizeof(dp));
        premax[N-1]=jobDifficulty[N-1];
        for(int i=N-2;i>=0;i--)
            premax[i]=max(premax[i+1],jobDifficulty[i]);
            
        return helper(jobDifficulty,0,d);
    }
};