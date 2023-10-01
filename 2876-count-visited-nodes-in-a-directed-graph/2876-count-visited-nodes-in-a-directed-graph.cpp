class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        vector<int>g[n];
        for(int i=0;i<n;i++) {
            g[i].push_back(edges[i]);
        }
        
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                unordered_map<int,int>v;
                int start=i;
                int c=0;
                
                while(1) {
                    c++;
                    v[start]=c;
                    start=edges[start];
                    if(vis[start]||v[start])break;
                }
            
                if(vis[start]) {
                    for(auto [x,y]:v) {
                        vis[x]=(c-y+1)+vis[start];
                    }
                }
                else {
                    int st=start;
                    int xx=0;
                    while(1) {
                        vis[st]=1;
                        xx++;
                        st=edges[st];
                        if(st==start)break;
                    }
             
                    for(auto &[x,y]:v) {
                        if(!vis[x])vis[x]=(c-y+1);
                        else vis[x]=xx;
                    }
                }
                
            }
        }
        
        return vis;
    }
};