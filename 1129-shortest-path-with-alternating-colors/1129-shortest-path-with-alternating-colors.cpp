class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<redEdges.size();i++)
        {
            graph[redEdges[i][0]].push_back({redEdges[i][1],(i+1)});
        }
        
        for(int i=0;i<blueEdges.size();i++)
        {
            graph[blueEdges[i][0]].push_back({blueEdges[i][1],-(i+1)});
        }
        
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>distr(n,1e9),distb(n,1e9);
        distr[0]=0,distb[0]=0;
    
        while(!q.empty())
        {
            auto [curr,edgecol]=q.front();
            q.pop();
            
            for(auto &[nbr,col]:graph[curr])
            {
                if(col*edgecol<=0)
                {
                    if(col<0&&distb[nbr]>distr[curr]+1)
                    {
                        distb[nbr]=distr[curr]+1;
                        q.push({nbr,col});
                    }
                    if(col>0&&distr[nbr]>distb[curr]+1)
                    {
                        distr[nbr]=distb[curr]+1;
                        q.push({nbr,col});
                    }
                } 
            }
        }
        
        vector<int>dist(n);
        for(int i=0;i<n;i++)
        {
            if(distr[i]==1e9&&distb[i]==1e9)dist[i]=-1;
            else
                dist[i]=min(distr[i],distb[i]);
        }
        
        return dist;
    }
};