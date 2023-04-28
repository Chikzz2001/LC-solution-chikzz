class Solution {
    class DSU {
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
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DSU dsu(n);
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                vector<int>v;
                for(int k=0;k<strs[i].length();k++) {
                    if(strs[i][k]!=strs[j][k]) {
                        v.push_back(k);
                    }
                }
                if(v.size()==0||(v.size()==2&&strs[i][v[0]]==strs[j][v[1]]&&strs[i][v[1]]==strs[j][v[0]])) {
                    dsu.is_joined(i,j);
                }
            }
        }
        
        set<int>parents;
        for(int i=0;i<n;i++) {
            parents.insert(dsu.find(i));
        }
        
        return parents.size();
    }
};