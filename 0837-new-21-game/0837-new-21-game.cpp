class Solution {
    int K,MP,N;
    // vector<double>dp;
    // double helper(int points) {
    //     if(points>=K)return points<=N?1.0:0.0;
    //     if(dp[points]!=-1)return dp[points];
    //     double p=0;
    //     //points+i>=K--> i>=K-points
    //     for(int i=1;i<=MP&&(points+i)<=N;i++) {
    //         p+=1.0/MP*helper(points+i);
    //     }
    //     return dp[points]=p;
    // }
public:
    double new21Game(int n, int k, int maxPts) {
        N=n,K=k,MP=maxPts;
        vector<double>dp(N+1);
        vector<double>sum(N+1);
        double s=0;
        for(int i=N;i>=K;i--) {
            dp[i]=1.0;
            sum[i]=1.0+s;
            s=sum[i];
        }
        
        for(int i=K-1;i>=0;i--) {
            double S=sum[i+1]-(i+MP+1<=N?sum[i+MP+1]:0);
            dp[i]=1.0/MP*S;
            sum[i]=(i==N?0:sum[i+1])+dp[i];
        }
        return dp[0];
    }
};