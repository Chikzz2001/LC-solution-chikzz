class Solution {
    int max_cycle_len=-1;
    vector<int>vis,dist;
    int steps=0;
    void dfs(vector<vector<int>>& graph,int node)
    {
        steps++;
        
        vis[node]=1;
        //cout<<node<<" "<<steps<<"\n";
        dist[node]=steps;
        for(auto &nbr:graph[node])
        {
            if(!vis[nbr])
            {
                dfs(graph,nbr);
            }
            else if(vis[nbr]==1)
            {
               max_cycle_len=max(max_cycle_len,steps+1-dist[nbr]); 
            }
        }
        
        vis[node]=2;
        steps--;
    }
public:
    int longestCycle(vector<int>& edges) 
    {
        int n=edges.size();
        vis=vector<int>(n,0);
        dist=vector<int>(n,1e7);
        
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
                graph[i].push_back(edges[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                steps=0;
                dfs(graph,i);
            }  
        }
        
        return max_cycle_len<=-1?-1:max_cycle_len;
    }
};