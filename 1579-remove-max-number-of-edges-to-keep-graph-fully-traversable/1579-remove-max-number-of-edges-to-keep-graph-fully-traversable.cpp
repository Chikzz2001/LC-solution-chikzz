class Solution {
     class DSU
    {
        int *par,*rank;
        public:
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
            if(par[x]==-1)par[x]=x;
            if(x==par[x])return x;
            return par[x]=find(par[x]);
        }
        
        bool join(int a,int b)
        {
            int pa=find(a);
            int pb=find(b);
            
            if(pa==pb)
            {
                return 1;
            }
            
            if(rank[pa]>rank[pb])
            {
                par[pb]=pa;
            }
            else if(rank[pa]<rank[pb])
            {
                par[pa]=pb;
            }
            else 
            {
                rank[pa]++;
                par[pb]=pa;
            }
            return 0;
        }
    };
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        DSU alice(n+1),bob(n+1);
        
        int count=0;
        for(auto &e:edges)
        {
            if(e[0]==3)
            {
                if(alice.join(e[1],e[2]))continue;
                bob.join(e[1],e[2]);
                count++;
            }
        }
        for(auto &e:edges)
        {
            if(e[0]==1)
            {
                if(alice.join(e[1],e[2]))continue;
                count++;
            }
            else if(e[0]==2)
            {
                if(bob.join(e[1],e[2]))continue;
                count++;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            if(!alice.join(i,i+1))return -1;
            if(!bob.join(i,i+1))return -1;
        }
        return edges.size()-count;
    }
};