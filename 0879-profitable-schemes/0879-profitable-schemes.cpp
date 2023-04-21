#define ll long long
class Solution {
    const int M=1e9+7;
    int dp[101][101][101];
    int N,PM;
    ll helper(vector<int>& group, vector<int>& profit, int n,int minProfit,int i,int P,int ppl) {
        if(i==profit.size()) {
            if(P>=minProfit&&ppl<=n)return 1;
            return 0;
        }
        if(ppl>n)return 0;
        if(dp[i][min(P,minProfit)][ppl]!=-1)return dp[i][min(P,minProfit)][ppl];
        ll op1=helper(group,profit,n,minProfit,i+1,P+profit[i],ppl+group[i])%M;
        ll op2=helper(group,profit,n,minProfit,i+1,P,ppl)%M;
        
        return dp[i][min(P,minProfit)][ppl]=(op1+op2)%M;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N=profit.size();
        memset(dp,-1,sizeof(dp));
        return helper(group,profit,n,minProfit,0,0,0);
    }
};