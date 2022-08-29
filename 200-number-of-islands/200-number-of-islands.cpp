class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int &n,int &m,vector<vector<int>>& dir)
    {
        if(i<0||i>=n||j<0||j>=m||grid[i][j]=='0')return;
        
        grid[i][j]='0';
        for(int k=0;k<4;k++)
        dfs(grid,i+dir[0][k],j+dir[1][k],n,m,dir);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
       vector<vector<int>>dir;
        dir.push_back({0,1,-1,0});
        dir.push_back({1,0,0,-1});
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j,n,m,dir);
                    count++;
                }
            }
        }
        return count;
    }
};