class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int &n,int &m,vector<vector<int>> &dir)
    {
        if(i<0||i>=n||j<0||j>=m||grid[i][j]==0)return 0;
        grid[i][j]=0;
        int sum=1;
        for(int k=0;k<4;k++)
            sum+=dfs(grid,i+dir[0][k],j+dir[1][k],n,m,dir);
        
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dir(2,vector<int>(4,0));
        dir[0][1]=dir[1][0]=1;
        dir[0][2]=dir[1][3]=-1;
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int ans=dfs(grid,i,j,n,m,dir);
                    maxx=max(maxx,ans);
                }
            }
        }
        return maxx;
    }
};