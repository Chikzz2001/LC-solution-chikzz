class Solution {
    struct node{
        int wt,u,v,i;
    };
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n);
        vector<node>sorted_Q;
        //offline queries supremacy
        for(int i=0;i<queries.size();i++){sorted_Q.push_back({queries[i][2],queries[i][0],queries[i][1],i});}
        sort(sorted_Q.begin(),sorted_Q.end(),[&](node &n1,node &n2){
            return n1.wt<n2.wt;
        });
        sort(edgeList.begin(),edgeList.end(),[&](vector<int>& v1,vector<int>& v2){
            return v1[2]<v2[2];
        });
        vector<bool>res(queries.size(),0);
        int j=0;
        for(int i=0;i<queries.size();i++){
            while(j<edgeList.size()&&edgeList[j][2]<sorted_Q[i].wt)dsu.is_joined(edgeList[j][0],edgeList[j][1]),j++;
            if(dsu.find(sorted_Q[i].u)==dsu.find(sorted_Q[i].v))res[sorted_Q[i].i]=1;
        }
        return res;
    }
};