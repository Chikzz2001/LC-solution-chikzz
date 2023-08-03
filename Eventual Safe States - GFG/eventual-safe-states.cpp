//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool dfs(vector<int>adj[],int node,vector<int>& vis,vector<int>& safe) {
        vis[node]=1;
        safe[node]=0;
        
        for(int child:adj[node]) {
            if(vis[child]==1) {
                return 1;
            }
            else if(vis[child]==0) {
                if(dfs(adj,child,vis,safe)) {
                    return 1;
                }
            }
        }
        
        vis[node]=2;
        safe[node]=1;
        return 0;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>vis(V,0),safe(V,0);
        for(int i=0;i<V;i++) {
            if(vis[i]==0)dfs(adj,i,vis,safe);
        }
        
        vector<int>res;
        for(int i=0;i<V;i++) {
            if(safe[i]==1)res.push_back(i);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends