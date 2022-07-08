class Solution {
    int dp[201][201];
    int dfs(int i,int j,vector<vector<int>>& grid,int &n,int &m)
    {
        if(i==n-1&&j==m-1)
        {
            return (grid[i][j]<0)?grid[i][j]:0;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        int temp=grid[i][j];
        grid[i][j]=1e4;
        
        int dir[2][2]={{1,0},{0,1}};
        
        int maxx=-1e7;
        for(int k=0;k<2;k++)
        {
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            
            
            if(ni<n&&nj<m&&grid[ni][nj]<=1e3)
                maxx=max(maxx,dfs(ni,nj,grid,n,m));
        }
        grid[i][j]=temp;
        
        int store=temp+maxx;
        return dp[i][j]=store<0?store:0;
    }
 public:
    int calculateMinimumHP(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int res=dfs(0,0,grid,n,m);
        return -res+1;
    }
};