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
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n+1);
        for(auto r:roads) {
            dsu.is_joined(r[0],r[1]);
        }
        
        int minn=1e9;
        for(auto r:roads) {
            int p0=dsu.find(r[0]);
            int p1=dsu.find(r[1]);
            int pp1=dsu.find(1);
            if(p0==pp1||p1==pp1)minn=min(minn,r[2]);
        }
        return minn;
    }
};