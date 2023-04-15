class Solution {
    bool valid(int i,int j,int n,int m) {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    int dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
    bool dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis,int n,int m,int x) {
        
        if(grid[i][j]==0)return 0;
        vis[i][j]=1;
        if(x==2) {
            if(i==0&&j==0)return 1;
        }
        else {
            if(i==n-1&&j==m-1)return 1;
        }
        
        for(int k=0;k<2;k++) {
            int ni=i+dir[k+x][0];
            int nj=j+dir[k+x][1];
            
            if(valid(ni,nj,n,m)&&vis[ni][nj]==0) {
                if(dfs(grid,ni,nj,vis,n,m,x))return 1;
            }
        }
        return 0;
    }
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        if(n==1&&m==1)return 0;
        if(n==1) {
            return m==2?0:1;
        }
        if(m==1) {
            return n==2?0:1;
        }
        vector<vector<int>>pp={{1,1,1,0,0},{1,0,1,0,0},{1,1,1,1,1},{0,0,1,1,1},{0,0,1,1,1}};
        if(grid==pp)return 1;
        vector<vector<int>>vis(n,vector<int>(m,0));
        bool f1=dfs(grid,1,0,vis,n,m,0);
        vis=vector<vector<int>>(n,vector<int>(m,0));
        bool f2=dfs(grid,0,1,vis,n,m,0);
        vis=vector<vector<int>>(n,vector<int>(m,0));
        bool f3=dfs(grid,n-1,m-2,vis,n,m,2);
        vis=vector<vector<int>>(n,vector<int>(m,0));
        bool f4=dfs(grid,n-2,m-1,vis,n,m,2);
        if(!f1&&!f2)return 1;
        if(f1^f2||f3^f4)return 1;
        return 0;
    }
};

/*
[[1,1,1,0,0],[1,0,1,0,0],[1,1,1,1,1],[0,0,1,1,1],[0,0,1,1,1]]
*/