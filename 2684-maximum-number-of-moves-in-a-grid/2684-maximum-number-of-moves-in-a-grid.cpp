class Solution {
    bool valid(int i,int j,int n,int m) {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    int dir[3][2]={{-1,-1},{0,-1},{1,-1}};
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)dp[i][0]=1;
        int res=1;
        for(int j=1;j<m;j++) {
            for(int i=0;i<n;i++) {
                for(int k=0;k<3;k++) {
                    int ni=i+dir[k][0],nj=j+dir[k][1];
                    if(valid(ni,nj,n,m)&&grid[i][j]>grid[ni][nj]&&dp[ni][nj])dp[i][j]=max(dp[i][j],1+dp[ni][nj]);
                }
                res=max(res,dp[i][j]);
            }
        }
        
        return res-1;
    }
};