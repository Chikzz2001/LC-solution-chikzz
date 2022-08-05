class Solution {
    const int M=1e9+7;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) 
    {
        //dist[node]>dist[nbr]-->restricted path
        
        vector<vector<pair<int,int>>>graph(n);
        for(auto &e:edges)
        {
            graph[e[0]-1].push_back({e[1]-1,e[2]});
            graph[e[1]-1].push_back({e[0]-1,e[2]});
        }
        
        priority_queue<pair<int,int>>pQ;
        pQ.push({0,n-1});
        
        vector<int>count(n,0),dist(n,INT_MAX);
        dist[n-1]=0;
        count[n-1]=1;
        
        while(!pQ.empty())
        {
            auto [d,node]=pQ.top();
            pQ.pop();
            d*=-1;
            
            if(d>dist[node])continue;
            
            for(auto &[nbr,nbr_dist]:graph[node])
            {
                if(dist[nbr]>dist[node]+nbr_dist)
                {
                    dist[nbr]=dist[node]+nbr_dist;
                    pQ.push({-dist[nbr],nbr});
                }
                if(dist[node]>dist[nbr])
                {
                    count[node]=(count[node]%M+count[nbr]%M)%M;
                }
            }
        }
        
        return count[0];
    }
};