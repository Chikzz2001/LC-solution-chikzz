class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i,int j,int &n,int &m)
    {
        if(grid[i][j]==1||grid[i][j]==-1)return 1;
        if(i==0||i==n-1||j==0||j==m-1)return 0;
        grid[i][j]=-1;
        bool up=dfs(grid,i-1,j,n,m);
        bool down=dfs(grid,i+1,j,n,m);
        bool left=dfs(grid,i,j-1,n,m);
        bool right=dfs(grid,i,j+1,n,m);
        return (up&&down&&left&&right);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    if(dfs(grid,i,j,n,m))count++;
                }
            }
        }
        return count;
    }
};