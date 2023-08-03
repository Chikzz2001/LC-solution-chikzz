//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    vector<int> Toposort(vector<vector<int>>adj[],int N) {
        
        vector<int>in(N,0);
        
        for(int i=0;i<N;i++) {
            for(auto nbr:adj[i]) {
                in[nbr[0]]++;
            }
        }
        
        queue<int>q;
        
        for(int i=0;i<N;i++) {
            if(in[i]==0)q.push(i);
        }
        
        vector<int>topo;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto nbr:adj[node]) {
                if(--in[nbr[0]]==0) {
                    q.push(nbr[0]);
                }
            }
        }
        
        return topo;
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<int>>adj[N];
        
        for(int i=0;i<M;i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int>topo=Toposort(adj,N);
        
        // for(int x:topo)cout<<x<<" ";
        // cout<<"\n";
        
        vector<int>dist(N,1e9);
        dist[0]=0;
        
        for(int i=0;i<topo.size();i++) {
            for(auto nbr:adj[topo[i]]) {
                dist[nbr[0]]=min(dist[nbr[0]],dist[topo[i]]+nbr[1]);
            }
        }
        
        for(int i=0;i<N;i++) {
            if(dist[i]==1e9)dist[i]=-1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends