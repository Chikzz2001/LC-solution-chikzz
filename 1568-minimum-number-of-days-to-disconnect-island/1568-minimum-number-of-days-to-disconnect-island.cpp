class Solution {
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool vis[31][31];
    int noOfIslands(vector<vector<int>>& grid,int &n,int &m)
    {
       int islands=0;
       memset(vis,0,sizeof(vis));
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j])
               {
                   islands++;
                   dfs(grid,i,j,n,m);
               }
           }
       }
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
               grid[i][j]=vis[i][j]?1:0;
       }
        
        return islands;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int &n,int &m)
    {
        if(i<0||j<0||i>=n||j>=m||!grid[i][j])return;
        vis[i][j]=1;
        grid[i][j]=0;
        
        for(int k=0;k<4;k++)
        {
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            
            dfs(grid,ni,nj,n,m);
        }
    }
public:
    int minDays(vector<vector<int>>& grid) 
    {
        //we can disconnect the island into 2 from the corner by at most 2 changes
        //00000     00000
        //01110     01010
        //01110---->00110
        //01110     01110
        //00000     00000
        
        //so basically in the worst case we need 2 steps-->ans can be 0,1,2
        
        int n=grid.size(),m=grid[0].size();
        
         //edge cases
        if(n==1&&m==1)
            return grid[0][0];
        
        if(n*m==2)
        {
            int countOnes=0;
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
              {if(grid[i][j]==1)countOnes++;}
          }
            return countOnes;
        }
        
        int initialIslands=noOfIslands(grid,n,m);

        //made mistake in the checking condition dumbo :'( islands must not be one that is it
        //zero islands are considered valid cases
        
        if(initialIslands!=1)return 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int islands=0;
                if(grid[i][j])
                {
                    int temp=grid[i][j];
                    grid[i][j]=0;
                    
                   islands=noOfIslands(grid,n,m);
                  if(islands!=1)return 1; 
                    
                    grid[i][j]=temp;
                }
            }
        }
        
        return 2;
    }
};

