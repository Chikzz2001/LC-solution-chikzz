class Solution {
    vector<int> distance_from_nodes(vector<vector<int>>& graph,int node,int n)
    {
        vector<int>dist(n,1e9),vis(n,0);
        dist[node]=0;
        queue<int>q;
        q.push(node);
        vis[node]=1;
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            
            for(auto &nbr:graph[curr])
            {
                if(!vis[nbr])
                {
                    dist[nbr]=dist[curr]+1;
                    vis[nbr]=1;
                    q.push(nbr);
                }
            }
        }
        return dist;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>>graph(n);
        
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
                graph[i].push_back(edges[i]);
        }
            
        vector<int>dist1,dist2;
        dist1=distance_from_nodes(graph,node1,n);
        dist2=distance_from_nodes(graph,node2,n);
        
        int minn=1e9,res=-1;
        for(int i=0;i<n;i++)
        {
            if(minn>max(dist1[i],dist2[i]))
            {
                res=i;
                minn=max(dist1[i],dist2[i]);
            }
        }
        return res;
            
    }
};