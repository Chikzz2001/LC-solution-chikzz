class Solution {
    vector<vector<int>>g;
    vector<int>parent,reach;
    void dfs(int node,int p)
    {
        parent[node]=p;
        for(auto nbr:g[node])
        {
            if(nbr!=p)
                dfs(nbr,node);
        }
    }
    void dfs1(int node,int time)
    {
        reach[node]=time;
        if(!node)return;
        dfs1(parent[node],time+1);
    }
    int dfs2(int node,int p,int timer,vector<int>& amount)
    {
        int res=-1e7;
        for(int nbr:g[node])
        {
            if(nbr!=p)
                res=max(res,dfs2(nbr,node,timer+1,amount));
        }
        if(node&&g[node].size()==1)res=0;
        int ans=res+(reach[node]<timer?0:(reach[node]==timer?amount[node]/2:amount[node]));
        //cout<<node<<" "<<ans<<"\n";
        return ans;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size();
        if(n==1)return amount[0];
        g=vector<vector<int>>(n+1);
        parent=vector<int>(n+1,-1);
        reach=vector<int>(n+1,1e7);
        for(auto &e:edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        dfs(0,-1);
        dfs1(bob,0);
        //for(int i=0;i<=n;i++)cout<<reach[i]<<" ";
        return dfs2(0,-1,0,amount);
    }
};