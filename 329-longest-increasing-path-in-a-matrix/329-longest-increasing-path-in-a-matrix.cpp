class Solution {
    int dp[201][201];
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool valid(int i,int j,int n,int m)
    {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    int dfs(vector<vector<int>>& matrix,int i,int j,int n,int m)
    {
        if(dp[i][j]!=-1)return dp[i][j];
        
        int res=1;
        for(int k=0;k<4;k++)
        {
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
    
            if(valid(ni,nj,n,m)&&matrix[ni][nj]>matrix[i][j])
            {
                res=max(res,1+dfs(matrix,ni,nj,n,m));
            }
        }
        return dp[i][j]=res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
       int n=matrix.size(),m=matrix[0].size();
        int res=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res=max(res,dfs(matrix,i,j,n,m));
            }
        }
        return res;
    }
};