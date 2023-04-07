class Solution {
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool valid(int i,int j,int n,int m)
    {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        grid[i][j]=2;
        
        for(int k=0;k<4;k++)
        {
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            
            if(valid(ni,nj,grid.size(),grid[0].size())&&grid[ni][nj]==1)
                dfs(grid,ni,nj);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
                dfs(grid,i,0);
            if(grid[i][m-1]==1)
                dfs(grid,i,m-1);
        }
         for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
                dfs(grid,0,i);
            if(grid[n-1][i]==1)
                dfs(grid,n-1,i);
        }
        
        int res=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(grid[i][j]==1)
                    res++;
            }
        }
        
        return res;
    }
};