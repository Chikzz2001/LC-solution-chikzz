class Solution {
    int dp[101][101][6];
    int order[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
    int helper(vector<vector<int>>& C,int i,int p,int config) {
        if(i==C.size()) {
            return 0;
        }
        if(p!=-1&&dp[i][p][config]!=-1)return dp[i][p][config];
        int res=0;
        //not take
        res=helper(C,i+1,p,config);
        //take
        if(p==-1) {
            for(int k=0;k<6;k++) {
                res=max(res,C[i][order[k][0]]+helper(C,i+1,i,k));
            }
        }
        else {
            for(int k=0;k<6;k++) {
                if(C[p][order[config][0]]>=C[i][order[k][0]]&&C[p][order[config][1]]>=C[i][order[k][1]]&&C[p][order[config][2]]>=C[i][order[k][2]]) {
                    res=max(res,C[i][order[k][0]]+helper(C,i+1,i,k));
                }
            }
        
        }
        
        if(p!=-1)dp[i][p][config]=res;
        return res;
    }
public:
    int maxHeight(vector<vector<int>>& C) {
        for(int i=0;i<C.size();i++) {
            sort(C[i].rbegin(),C[i].rend());
        }
        sort(C.rbegin(),C.rend());
        memset(dp,-1,sizeof(dp));
        int maxx=0;
        // for(int i=0;i<6;i++) {
        //     maxx=max(maxx,helper(cuboids,0,0,i));
        // }
        
        return helper(C,0,-1,0);
    }
};