class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        vector<vector<pair<int,int>>>graph(n);
        
        //use positive edge-wt for red-edges
        for(auto &r:redEdges)
        {
            graph[r[0]].push_back({r[1],1});
        }
        
        //use negative edge-wt for blue-edges
        for(auto &b:blueEdges)
        {
            graph[b[0]].push_back({b[1],-1});
        }
        
        //node-->{current vertex,edge color through which we accessed it}
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