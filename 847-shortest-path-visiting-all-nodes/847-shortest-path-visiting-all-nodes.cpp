class Solution {
     bool vis[1<<12][12];
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        if(!graph.size())
            return 0;
        
        queue<pair<int,int>>q;
         int n=graph.size();
       
        for(int i=0;i<n;i++)
        {
            q.push({i,(1<<i)});
            vis[1<<i][i]=1;
        }
        
        int shortest_path=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto [node,mask]=q.front();
                q.pop();
                
                if(mask==(1<<n)-1)return shortest_path;
                
                for(auto &nbr:graph[node])
                {
                    int temp_mask=mask|(1<<nbr);
                    if(!vis[temp_mask][nbr])
                    {
                        if(temp_mask==(1<<n)-1)return shortest_path+1;
                        q.push({nbr,temp_mask});
                        vis[temp_mask][nbr]=1;
                    }
                }
            }
            shortest_path++;
        }
        return -1;
    }
};