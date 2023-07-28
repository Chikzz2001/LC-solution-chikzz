class Solution {
    int dp[100100][3];
    int helper(vector<int>& P,int i,int segs,int k) {
        if(i>=P.size())return 0;
        if(segs==0)return 0;
        if(dp[i][segs]!=-1)return dp[i][segs];
        //take
        int next_idx=upper_bound(P.begin(),P.end(),P[i]+k)-P.begin()-1;
        int op1=(next_idx-i+1)+helper(P,next_idx+1,segs-1,k);
        
        //not_take
        int op2=helper(P,i+1,segs,k);
        
        return dp[i][segs]=max(op1,op2);
    }
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(prizePositions,0,2,k);
    }
};