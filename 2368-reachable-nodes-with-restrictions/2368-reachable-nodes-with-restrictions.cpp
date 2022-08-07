class Solution {
    set<int>R;
    int dfs(int node,int par,vector<vector<int>>& graph)
    {
        int cnt=1;
        for(auto &nbr:graph[node])
        {
            if(nbr!=par&&!R.count(nbr))
                cnt+=dfs(nbr,node,graph);
        }
        return cnt;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>graph(n);
        for(auto &e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for(auto &x:restricted)
            R.insert(x);
        
        if(R.count(0))return 0;
        return dfs(0,-1,graph);
    }
};