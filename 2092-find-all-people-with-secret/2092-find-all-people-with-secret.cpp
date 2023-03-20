class Solution {
    class DSU {
        vector<int>par,size;
        public:
        DSU(int n) {
            par=vector<int>(n);
            size=vector<int>(n,1);
            for(int i=0;i<n;i++)par[i]=i;
        }
        
        int find(int x) {
            if(x==par[x])return x;
            return par[x]=find(par[x]);
        }
        
        void join(int a,int b) {
            int pa=find(a);
            int pb=find(b);
            par[pa]=pb;
        }
        
        void reset(int a) {
            par[a]=a;
        }
    };
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        map<int,vector<pair<int,int>>>m;
        for(auto meet:meetings) {
            m[meet[2]].push_back({meet[0],meet[1]});
        }
        
        DSU dsu(n);
        dsu.join(0,firstPerson);
        
        for(auto [x,y]:m) {
            set<int>S;
            for(auto [u,v]:y) {
                dsu.join(u,v);
                S.insert(u);
                S.insert(v);
            }
            int p0=dsu.find(0);
            for(int z:S) {
                int pz=dsu.find(z);
                if(p0!=pz)dsu.reset(z);
            }
        }
        
        vector<int>res;
        for(int i=0;i<n;i++) {
            if(dsu.find(0)==dsu.find(i)) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
