class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        if(!graph.size())
            return 0;
        
        queue<pair<int,int>>q;
        set<pair<int,int>>vis;
        
        int n=graph.size();
        for(int i=0;i<n;i++)
        {
            q.push({i,(1<<i)});
            vis.insert({i,(1<<i)});
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
                    if(!vis.count({nbr,temp_mask}))
                    {
                        if(temp_mask==(1<<n)-1)return shortest_path+1;
                        q.push({nbr,temp_mask});
                        vis.insert({nbr,temp_mask});
                    }
                }
            }
            shortest_path++;
        }
        return -1;
    }
};