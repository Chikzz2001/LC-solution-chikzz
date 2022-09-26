class Solution {
    class DSU
    {
        public:
        int *par,*rank;
        DSU(int n)
        {
            par=new int[n];
            rank=new int[n];
            
            for(int i=0;i<n;i++)
            {
                par[i]=i;
                rank[i]=1;
            }
        }
            
            int find(int x)
            {
                if(x==par[x])
                    return x;
                return par[x]=find(par[x]);
            }
            
            bool join(int a,int b)
            {
                int pa=find(a);
                int pb=find(b);
                
                if(pa==pb)
                    return 1;
                
                if(rank[pa]<rank[pb])
                {
                    par[pa]=pb;
                }
                else if(rank[pa]>rank[pb])
                {
                    par[pb]=pa;
                }
                else
                {
                    par[pb]=pa;
                    rank[pa]++;
                }
                return 0;
            }
    };
public:
    bool equationsPossible(vector<string>& equations) 
    {
        DSU dsu(26);
        
        set<pair<int,int>>not_equal;
        for(auto &e:equations)
        {
            int f=e[0]-'a',s=e[3]-'a';
            if(e[1]=='=')
                dsu.join(f,s);
            else
                not_equal.insert({f,s});
        }
        
        for(auto &[u,v]:not_equal)
        {
            dsu.find(u);
            dsu.find(v);
            if(dsu.par[u]==dsu.par[v])return 0;
        }
        
        return 1;
    }
};