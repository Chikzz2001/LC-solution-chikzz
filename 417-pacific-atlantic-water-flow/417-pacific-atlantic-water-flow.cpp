class Solution {
    set<pair<int,int>>S;
    vector<vector<int>>res;
    vector<vector<bool>>vis;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs1(vector<vector<int>>& heights,int i,int j,vector<vector<bool>>& vis)
    {
        if(vis[i][j])return;
        int height=heights[i][j];
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            
            if(ni>=0&&nj>=0&&ni<heights.size()&&nj<heights[0].size()&&heights[ni][nj]>=height)
                dfs1(heights,ni,nj,vis);
        }
    }
    void dfs2(vector<vector<int>>& heights,int i,int j)
    {
        if(heights[i][j]==-1)return;
        if(vis[i][j])
        res.push_back({i,j});
        int height=heights[i][j];
        heights[i][j]=-1;
        for(int k=0;k<4;k++)
        {
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            
            if(ni>=0&&nj>=0&&ni<heights.size()&&nj<heights[0].size()&&heights[ni][nj]>=height)
                dfs2(heights,ni,nj);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int n=heights.size(),m=heights[0].size();
        
        vis=vector<vector<bool>>(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++)
        dfs1(heights,i,0,vis);
        
         for(int i=0;i<m;i++)
        dfs1(heights,0,i,vis);
        
        for(int i=0;i<n;i++)
        dfs2(heights,i,m-1);
        
         for(int i=0;i<m;i++)
        dfs2(heights,n-1,i);
            
        return res;
    }
};