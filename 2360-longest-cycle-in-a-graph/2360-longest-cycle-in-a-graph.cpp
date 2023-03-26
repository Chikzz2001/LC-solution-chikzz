class Solution {
    int maxlen=-1;
    void dfs(vector<int>& edges,vector<int>& vis,int node,int time) {
        vis[node]=time;
        if(edges[node]==-1){vis[node]+=100000;return;}
        if(!vis[edges[node]])dfs(edges,vis,edges[node],time+1);
        else if(vis[edges[node]]<=100000) {
            maxlen=max(maxlen,time+1-vis[edges[node]]);
        }
        vis[node]+=100000;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(edges,vis,i,1);
            }
        }
        
        return maxlen;
    }
};