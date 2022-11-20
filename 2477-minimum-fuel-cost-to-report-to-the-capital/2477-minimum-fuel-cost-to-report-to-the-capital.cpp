#define ll long long int
#define min(a,b) a<b?a:b
class Solution {
    struct node
    {
        ll reps,cost,cars;
    };
    vector<int>vis;
    int S;
    node dfs(vector<vector<int>>& g,int c)
    {
        vis[c]=1;
        ll reps=0,tot_cost=0,cars=0;
        for(auto &nbr:g[c])
        {
            if(!vis[nbr])
            {
               auto [_reps,_cost,_cars]=dfs(g,nbr);
               reps+=_reps;tot_cost+=_cost,cars+=_cars;
            }   
        }
        if(c==0)return {reps,tot_cost,cars};
        if(g[c].size()==1)return {1,1,1};
        ll req_cars=min(cars+1,((reps+1)%S?(reps+1)/S+1:(reps+1)/S));
        return {reps+1,tot_cost+req_cars,req_cars};
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();S=seats;
        vector<vector<int>>g(n+1);
        vis=vector<int>(n+1,0);
        for(auto &e:roads)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return dfs(g,0).cost;
    }
};