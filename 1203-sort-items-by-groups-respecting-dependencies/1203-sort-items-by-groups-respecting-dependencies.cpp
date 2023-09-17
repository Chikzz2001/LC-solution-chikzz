class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        map<int,set<int>>M;
        
        set<int>S;
        map<int,int>in;
        for(int i=0;i<n;i++) {
            for(int x:beforeItems[i]) {
                int ga,gb;
                ga=group[x]==-1?m+x:group[x];
                gb=group[i]==-1?m+i:group[i];
                if(ga==gb)continue;
                S.insert(ga);
                S.insert(gb);
                M[ga].insert(gb);
            }
        }
        
        for(auto [a,b]:M) {
            for(auto x:b)in[x]++;
        }
        
        
        // for(auto [u,v]:in)cout<<u<<" "<<v<<"\n";
        
        queue<int>q;
        for(auto [a,b]:M) {
            if(a>=m&&!in.count(a))q.push(a);
        }
        for(int i=0;i<m;i++) {
            S.insert(i);
            if(!in.count(i))q.push(i);
        }
    
        vector<int>tp1;
        while(!q.empty()) {
            int curr=q.front();q.pop();
            tp1.push_back(curr);
            for(int c:M[curr]) {
                if(--in[c]==0) {
                    q.push(c);
                }
            }
        }
        
        // for(int x:tp1)cout<<x<<" ";
        if(tp1.size()!=S.size())return {};
        // cout<<"hi";
    
        vector<int>mk(m,0);
        for(int x:tp1) {
            if(x<m)mk[x]=1;
        }
        for(int i=0;i<m;i++) {
            if(!mk[i])tp1.push_back(i);
        }
        
        // for(int x:tp1)cout<<x<<"\n";
        map<int,map<int,vector<int>>>g;
        
        for(int i=0;i<n;i++) {
            for(int x:beforeItems[i]) {
                if(group[x]==group[i])g[group[i]][x].push_back(i);
            }
        }
        
        vector<int>res;
        vector<int>mark(n,0);
        map<int,vector<int>>nodes;
        for(int i=0;i<n;i++) {
            nodes[group[i]].push_back(i);
        }
        
        for(int i=0;i<tp1.size();i++) {
            if(tp1[i]>=m)res.push_back(tp1[i]-m),mark[tp1[i]-m]=1;
            else {
                queue<int>q;
                map<int,int>ind;
                set<int>S1;
                for(auto [u,v]:g[tp1[i]]) {
                    S1.insert(u);
                    for(int z:v) {
                        ind[z]++;
                        S1.insert(z);
                    }
                }
                for(int u:nodes[tp1[i]]) {
                    S1.insert(u);
                    if(!ind.count(u)) {
                        q.push(u);
                        // cout<<tp1[i]<<" "<<u<<"\n";
                    }
                    else {
                        // cout<<tp1[i]<<" "<<u<<" "<<ind[u]<<"\n";
                    }
                }


                vector<int>tp2;
                while(!q.empty()) {
                    int curr=q.front();q.pop();
                    tp2.push_back(curr);
                    for(int c:g[tp1[i]][curr]) {
                        if(--ind[c]==0) {
                            q.push(c);
                        }
                    }
                }

                
                if(tp2.size()!=S1.size()) {
                    // cout<<"NO"<<"\n";
                    // for(int x:tp2)cout<<x<<" ";
                    // cout<<"\n";
                    return {};
                }
                for(int x:tp2)res.push_back(x),mark[x]=1;
                    
                }
            }
        
        for(int i=0;i<n;i++) {
            if(!mark[i])res.push_back(i);
        }
        
        return res;
    }
};

/*
5
3
[0,0,2,1,0]
[[3],[],[],[],[1,3,2]]

5
5
[2,0,-1,3,0]
[[2,1,3],[2,4],[],[],[]]
*/