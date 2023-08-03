//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int>adj[],int node,vector<int>& vis) {
        vis[node]=1;
        
        for(int child:adj[node]) {
            if(vis[child]==1) {
                return 1;
            }
            else if(vis[child]==0) {
                if(dfs(adj,child,vis)) {
                    return 1;
                }
            }
        }
        
        vis[node]=2;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++) {
            if(vis[i]==0) {
                if(dfs(adj,i,vis))return 1;
            }
        }
        return 0;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends