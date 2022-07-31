class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                queue<int>q;
                q.push(i);
                color[i]=1;
                while(!q.empty())
                {
                    int size=q.size();
                    while(size--)
                    {
                        int curr=q.front();q.pop();
                        
                        for(auto &nbr:graph[curr])
                        {
                            if(color[nbr]==-1)
                            {
                                q.push(nbr);
                                color[nbr]=1-color[curr];
                            }
                            else if(color[nbr]==color[curr])
                                return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};