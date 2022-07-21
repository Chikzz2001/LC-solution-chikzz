class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<pair<int,int>>>graph(n);
        for(auto &c:connections)
        {
            graph[c[0]].push_back({c[1],1});
            graph[c[1]].push_back({c[0],0});
        }
        
        deque<pair<int,int>>dQ;
        dQ.push_back({0,0});
        vector<int>dist(n,1e9);
        vector<bool>vis(n,0);
        dist[0]=0;
        
        int reverse_edges=0;
        while(!dQ.empty())
        {
            auto [curr,blocked]=dQ.front();
            dQ.pop_front();
            vis[curr]=1;
            
            if(blocked)
                reverse_edges++;
            
            for(auto &[nbr,d]:graph[curr])
            {
                if(!vis[nbr])
                {
                    if(d==1)
                    {
                        if(dist[nbr]>dist[curr]+1)
                        {
                            dist[nbr]=dist[curr]+1;
                            dQ.push_back({nbr,1});
                        }
                    }
                    else
                    {
                        if(dist[nbr]>dist[curr])
                        {
                            dist[nbr]=dist[curr];
                            dQ.push_front({nbr,0});
                        }
                    }
                }
            }
        }
        
        return reverse_edges;
    }
};