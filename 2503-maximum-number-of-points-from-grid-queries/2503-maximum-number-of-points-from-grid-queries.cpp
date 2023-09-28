class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<vector<int>>v;
     
        int qn=queries.size();
        for(int i=0;i<qn;i++)
        v.push_back({queries[i],i});
        sort(v.begin(),v.end());
        vector<int>res(qn);
        int itr=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        int n=grid.size(),m=grid[0].size();
      
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=1;
        int dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
        int tot=0;
        while(!q.empty())
        {
            queue<pair<int,int>>_q;
            while(!q.empty())
            {
                 auto [i,j]=q.front();q.pop();
                 if(grid[i][j]>=v[itr][0]){_q.push({i,j});continue;}
                tot++;
                for(int k=0;k<4;k++)
                {
                    int ni=i+dir[k][0];
                    int nj=j+dir[k][1];

                    if(ni>=0&&nj>=0&&ni<n&&nj<m&&!vis[ni][nj])
                    {
                        q.push({ni,nj});
                        vis[ni][nj]=1;
                    }
                }
            }
            q=_q;
            int x=v[itr][0];
            while(itr!=qn&&v[itr][0]==x) {
                 res[v[itr++][1]]=tot;
            }
            if(itr==qn)break;
        }
        while(itr!=qn)res[v[itr++][1]]=tot;
        return res;
    }
};