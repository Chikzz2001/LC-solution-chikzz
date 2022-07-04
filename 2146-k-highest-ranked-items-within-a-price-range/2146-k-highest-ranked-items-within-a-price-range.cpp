class Solution {
    struct node{
        int x,y,p,level;
    };
 
    static bool comp(const node& c1,const node& c2)
    {
        if(c1.level!=c2.level)
            return c1.level<c2.level;
        else if(c1.p!=c2.p)
            return c1.p<c2.p;
        else if(c1.x!=c2.x)
            return c1.x<c2.x;
        return c1.y<c2.y;
            
    }
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        queue<node>q;
        vector<node>v;
        q.push({start[0],start[1],grid[start[0]][start[1]],0});
        set<pair<int,int>>s;
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            level++;
            while(size--)
            {
                auto [x,y,p,l]=q.front();
        
            if(p>=pricing[0]&&p<=pricing[1]&&p!=1)
            v.push_back(q.front());
            
            grid[x][y]=0;
            q.pop();
            
            
            
            int dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
            
            for(int i=0;i<4;i++)
            {
                int ni=x+dir[i][0];
                int nj=y+dir[i][1];
                
                if(ni>=0&&nj>=0&&ni<grid.size()&&nj<grid[0].size()&&grid[ni][nj]!=0)
                {
                    if(!s.count({ni,nj}))
                    {q.push({ni,nj,grid[ni][nj],level});
                     s.insert({ni,nj});}
                }
            }
            }
        }
        // for(auto &it:v)
        //     cout<<it.x<<" "<<it.y<<"\n";
        sort(v.begin(),v.end(),comp);
        vector<vector<int>>res;
        
        for(int i=0;i<v.size()&&i<k;i++)
            res.push_back({v[i].x,v[i].y});

        return res;
    }
};