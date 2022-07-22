class Solution {
    map<pair<string,string>,int>available;
    map<string,vector<string>>graph;
    vector<string>res;
    int N;
    bool dfs(string node)
    {
        res.push_back(node);
        if(res.size()==N+1)return 1;
        
        for(auto &nbr:graph[node])
        {
            if(available[{node,nbr}])
            {
                available[{node,nbr}]--;
                if(dfs(nbr))
                {return 1;}
                available[{node,nbr}]++;
            }
        }
        res.pop_back();
        return 0;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        N=tickets.size();
        for(auto &t:tickets)
        {
            graph[t[0]].push_back(t[1]);
            available[{t[0],t[1]}]++;
        }
        for(auto &[node,nbrs]:graph)
            sort(nbrs.begin(),nbrs.end());
        
        dfs("JFK");
        return res;
    }
};