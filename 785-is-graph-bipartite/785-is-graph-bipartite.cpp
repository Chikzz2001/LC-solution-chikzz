class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
               stack<int>st;
                st.push(i);
                color[i]=1;
                while(!st.empty())
                {
                    int curr=st.top();
                    st.pop();
                    for(auto &nbr:graph[curr])
                    {
                        if(color[nbr]==color[curr])
                            return 0;
                        else if(color[nbr]==-1)
                        {
                            color[nbr]=1-color[curr];
                            st.push(nbr);
                        }
                    }
                }
            }
        }
        return 1;
    }
};

/*


if(color[node]==color[par])return 0;
color[node]=1-color[par];
for(auto &nbr:graph[node])
{
    if(color[nbr]==-1)
    {
        if(!dfs(nbr,node))
        return 0;
    }
    return 1;
}



*/