class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int n=maze.size(),m=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        
        maze[entrance[0]][entrance[1]]='+';
        int dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
        
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto [i,j]=q.front();
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    int ni=i+dir[k][0];
                    int nj=j+dir[k][1];
                    if(ni>=0&&ni<n&&nj>=0&&nj<m&&maze[ni][nj]=='.')
                    {
                        if(ni==0||ni==n-1||nj==0||nj==m-1)
                            return level+1;
                        maze[ni][nj]='+';
                        q.push({ni,nj});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};