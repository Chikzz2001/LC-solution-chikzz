class Solution {
    bool vis[1682][41][41];
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        queue<pair<int,pair<int,int>>>Q;
        
        int n=grid.size(),m=grid[0].size();
        
        Q.push({0,{0,0}});
        
        vis[0][0][0]=1;
        
        int level=0;
    
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(Q.size())
        {
            int size=Q.size();
            while(size--)
            {
                auto [blocks,P]=Q.front();
                auto [i,j]=P;
                Q.pop();
                
                blocks+=(grid[i][j]==1);
                if(blocks==k+1)continue;
                
                if(i==n-1&&j==m-1)return level;
            
                for(int l=0;l<4;l++)
                {
                    int ni=i+dir[l][0];
                    int nj=j+dir[l][1];
                
                    if(ni>=0&&nj>=0&&ni<n&&nj<m&&!vis[blocks][ni][nj])
                    {
                        if(blocks<=k&&ni==n-1&&nj==m-1)
                            return level+1;
                        
                        vis[blocks][ni][nj]=1;
                        Q.push({blocks,{ni,nj}});
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};