class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        priority_queue<pair<int,pair<int,int>>>pQ;
        
        pQ.push({-grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];
        
        int dir[2][2]={{1,0},{0,1}};
        
        while(!pQ.empty())
        {
            auto [wt,P]=pQ.top();
            auto [i,j]=P;
            
            pQ.pop();
            grid[i][j]=-1;
            wt*=-1;
            
            for(int k=0;k<2;k++)
            {
                int ni=i+dir[k][0];
                int nj=j+dir[k][1];
                
                if(ni>=0&&nj>=0&&ni<n&&nj<m&&grid[ni][nj]>=0)
                {
                    if(grid[ni][nj]+wt<dist[ni][nj])
                    {
                        dist[ni][nj]=grid[ni][nj]+wt;
                        pQ.push({-dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};