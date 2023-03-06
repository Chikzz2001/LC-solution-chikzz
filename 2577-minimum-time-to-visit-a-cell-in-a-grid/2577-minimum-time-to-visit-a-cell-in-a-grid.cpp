class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{0,0}});
        
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty()) {
            auto [wt,P]=pq.top();
            auto [i,j]=P;
            pq.pop();
            wt*=-1;
            if(-wt>dist[i][j])continue;
            bool f=0;
            for(int k=0;k<4;k++) {
                int ni=i+dir[k][0];
                int nj=j+dir[k][1];
                
                if(ni>=0&&nj>=0&&ni<n&&nj<m&&grid[ni][nj]<=1+dist[i][j]) {
                    f=1;
                }
            }
            if(f) {
                for(int k=0;k<4;k++) {
                int ni=i+dir[k][0];
                int nj=j+dir[k][1];
                
                if(ni>=0&&nj>=0&&ni<n&&nj<m&&dist[ni][nj]>1+dist[i][j]) {
                    int diff=grid[ni][nj]-dist[i][j];
                   dist[ni][nj]=max(dist[i][j]+(diff&1?diff:diff+1),1+dist[i][j]);
                   pq.push({-dist[ni][nj],{ni,nj}});
                }
                }
            }
        }
        
        return dist[n-1][m-1]==1e9?-1:dist[n-1][m-1];
    }
};