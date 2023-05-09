class Solution {
    int rotate[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int vis[11][11];
    int n,m;
    vector<int>res;
    
    bool valid(int i,int j)
    {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    
    void dfs(int x,int y,vector<vector<int>>& matrix,int &dir)
    {
        vis[x][y]=matrix[x][y];
        res.push_back(matrix[x][y]);
       
        int nextx=x+rotate[dir][0];
        int nexty=y+rotate[dir][1];
        
        if(valid(nextx,nexty)&&vis[nextx][nexty]==1e4)
            dfs(nextx,nexty,matrix,dir);
        else
        {
            dir=(dir+1)%4;
            nextx=x+rotate[dir][0];
            nexty=y+rotate[dir][1];
                
            if(valid(nextx,nexty)&&vis[nextx][nexty]==1e4)
            dfs(nextx,nexty,matrix,dir);
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        for(int i=0;i<11;i++)
        {
            for(int j=0;j<11;j++)
                vis[i][j]=1e4;
        }
        int dir=1;
        n=matrix.size();
        m=matrix[0].size();
        dfs(0,0,matrix,dir);
        return res;
    }
};