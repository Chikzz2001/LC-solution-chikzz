class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        deque<pair<int,int>>dQ;
        dQ.push_back({0,0});
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        while(!dQ.empty())
        {
                auto [i,j]=dQ.front();
                dQ.pop_front();
            
                if(i==n-1&&j==m-1)
                    return dist[n-1][m-1];
                grid[i][j]=2;
                for(int k=0;k<4;k++)
                {
                    int ni=i+dir[k][0];
                    int nj=j+dir[k][1];
                
                    if(ni>=0&&nj>=0&&ni<n&&nj<m&&grid[ni][nj]!=2)
                    {
                        if(grid[ni][nj]==0&&dist[ni][nj]>dist[i][j])
                        {  
                            dist[ni][nj]=dist[i][j];
                            dQ.push_front({ni,nj});
                        }
                        else if(dist[ni][nj]>1+dist[i][j])
                        {
                            dist[ni][nj]=1+dist[i][j];
                            dQ.push_back({ni,nj});
                        }
                    }
                }
        }      
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //         cout<<dist[i][j]<<" ";
        //     cout<<"\n";
        // }
        return dist[n-1][m-1];
    }
};