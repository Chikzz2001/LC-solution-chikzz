class Solution {
        class DSU
    {
        public:
        vector<int>par,size;
        DSU(int n)
        {par=vector<int>(n);size=vector<int>(n);for(int i=0;i<n;i++){par[i]=i;size[i]=1;}}
        int find(int x){if(x==par[x])return x;return par[x]=find(par[x]);}
        bool is_joined(int a,int b){int pa=find(a);int pb=find(b);
        if(pa==pb)return 1;
        if(size[pa]<=size[pb]){par[pa]=pb;size[pb]+=size[pa];}
        else{par[pb]=pa;size[pa]+=size[pb];}
        return 0;}
    };
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long res=(1ll*n*(n-1))/2;
        DSU dsu(n);
        for(auto e:edges)dsu.is_joined(e[0],e[1]);
        
        set<int>P;
        for(int i=0;i<n;i++)P.insert(dsu.find(i));
        
        for(int x:P) {
            int y=dsu.size[x];
            res-=(1ll*y*(y-1))/2;
        }
        
        return res;
    }
};