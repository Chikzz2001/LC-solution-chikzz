class Solution {
    bool f=0;
    int c=0;
    //int dp[101][101][10001];
    bool dfs(vector<vector<char>>& grid,int i,int j,int &n,int &m, vector<vector<vector<int>>>& dp)
    {
        if(f)return 1;
        if(i>=n||j>=m)return 0;
        
        if(i==n-1&&j==m-1)
        {
            if(c==1){f=1;return 1;}
            return 0;
        }
        
        if(dp[i][j][c]!=-1)
            return dp[i][j][c];
        
        if(grid[i][j]=='(')
            c++;
        else
        {
            if(c)c--;
            else
                return 0;
        }
        
        bool flag=0;
        flag|=dfs(grid,i+1,j,n,m,dp);
        flag|=dfs(grid,i,j+1,n,m,dp);
        
        c=grid[i][j]=='('?c-1:c+1;
        return dp[i][j][c]=flag?1:0;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==')'||grid[n-1][m-1]=='(')return 0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m+n-1,-1)));
        return dfs(grid,0,0,n,m,dp);
    }
};