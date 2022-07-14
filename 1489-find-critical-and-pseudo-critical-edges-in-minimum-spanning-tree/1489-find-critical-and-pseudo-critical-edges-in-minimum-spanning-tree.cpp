class Solution {
    class DSU
    {
        vector<int>par,size;
        public:
        DSU(int n)
        {
            par=vector<int>(n);
            size=vector<int>(n,1);
            for(int i=0;i<n;i++)par[i]=i;
        }
        int find(int x)
        {
            if(par[x]==x)return x;
            return par[x]=find(par[x]);
        }
        bool join(int a,int b)
        {
            int pa=find(a);
            int pb=find(b);
            if(pa==pb)return 1;
            if(size[pa]>=size[pb])
            {
                par[pb]=pa;
                size[pa]+=size[pb];
            }
            else
            {
                par[pa]=pb;
                size[pb]+=size[pa];
            }
            return 0;
        }
    };
    int find_wt(vector<vector<int>>edges,int id,int n,bool add)
    {
        priority_queue<pair<int,pair<int,int>>>pQ;
        DSU dsu(n);
        int edges_in_MST=0,wt_of_MST=0;
        if(add)
        {
            wt_of_MST+=edges[id][2];
            dsu.join(edges[id][0],edges[id][1]);
            edges_in_MST++;
        }
        int i=0;
        for(auto &e:edges)
        {
            if(i==id){i++;continue;}
            pQ.push({-e[2],{e[0],e[1]}});
            i++;
        }
        
        while(!pQ.empty())
        {
            if(edges_in_MST==n-1)break;
            auto [wt,P]=pQ.top();
            auto [u,v]=P;
            pQ.pop();
            
            if(!dsu.join(u,v))
            {
                edges_in_MST++;
                wt_of_MST-=wt;
            }
        }
        set<int>par;
        for(int i=0;i<n;i++)
            par.insert(dsu.find(i));
        return par.size()==1?wt_of_MST:-1;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {
        priority_queue<pair<int,pair<int,int>>>pQ;
        // vector<vector<int>>edges_in_MST;
        set<int>MST_idx;
        map<pair<int,int>,int>idx;
        set<int>wts;
        int i=0;
        for(auto &e:edges)
        {
            pQ.push({-e[2],{e[0],e[1]}});
            idx[{e[0],e[1]}]=i++;
        }
        
        DSU dsu(n);
        int edges_in_MST=0,wt_of_MST=0;
        while(!pQ.empty())
        {
            if(edges_in_MST==n-1)break;
            auto [wt,P]=pQ.top();
            auto [u,v]=P;
            pQ.pop();
            
            if(!dsu.join(u,v))
            {
                //edges_in_MST.push_back({u,v,-wt});
                MST_idx.insert(idx[{u,v}]);
                edges_in_MST++;
                wt_of_MST-=wt;
                wts.insert(-wt);
            }
        }
        
        vector<vector<int>>res;
        vector<int>critical,pseudo_critical;
        int id=0;
        for(auto &e:edges)
        {
            int wt=find_wt(edges,id,n,0);
            if(wt>wt_of_MST||wt==-1)
                critical.push_back(id);
            else
            {
                int wt=find_wt(edges,id,n,1);
                if(wt==wt_of_MST)
                pseudo_critical.push_back(id);
            }
            id++;
        }
        res.push_back(critical);
        res.push_back(pseudo_critical);
        return res;
    }
};

/*
6
[[0,1,1],[1,2,1],[0,2,1],[2,3,4],[3,4,2],[3,5,2],[4,5,2]]
6
[[0,1,2],[0,2,5],[2,3,5],[1,4,4],[2,5,5],[4,5,2]]

*/