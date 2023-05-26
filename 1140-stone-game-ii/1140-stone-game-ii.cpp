class Solution {
    int dp[101][201];
    
    int help(int i,int M,vector<int>& p)
    {
        if(i>=p.size())return 0;
        
        if(dp[i][M]!=-1)return dp[i][M];
        int total=0;
        int res=INT_MIN;
        for(int j=0;j<2*M;j++)
        {
            if((i+j)<p.size())total+=p[i+j];
            res=max(res,total-help(i+j+1,max(M,j+1),p));
        }
        return dp[i][M]=res;
    }
public:
    int stoneGameII(vector<int>& p) {
      int sum=0;
      for(auto &x:p)sum+=x;
        
        memset(dp,-1,sizeof(dp));
        
        //maximum difference between the stones collected by Alice and Bob
        int diff=help(0,1,p);
        
        //sum=A+B diff=max value of (A-B)   
        //sum+diff=(A+B)+(A-B)=2A
        return (sum+diff)/2;
    }
};