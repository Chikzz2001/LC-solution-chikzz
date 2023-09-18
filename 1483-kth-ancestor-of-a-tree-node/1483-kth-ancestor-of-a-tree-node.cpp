class TreeAncestor {
    int dp[50001][20];
public:
    TreeAncestor(int n, vector<int>& parent) 
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++) {
            if(parent[i]!=-1)
            dp[i][0]=parent[i];
        }
        
        for(int j=1;j<20;j++) {
            for(int i=0;i<n;i++) {
                if(dp[i][j-1]!=-1)
                dp[i][j]=dp[dp[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) 
    {
        int par=node;
        for(int i=0;i<20;i++) {
            if(k&(1<<i)) {
                par=dp[par][i];
                if(par==-1)break;
            }
        }
        //3rd parent of x   x-->y-->z-->w
        return par;
    }
};
/*

dp[i][j]-->(2^j)th parent of i


*/

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */