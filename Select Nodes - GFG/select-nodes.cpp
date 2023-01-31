//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

int dp[100100][2];
class Solution{
    int helper(vector<int>g[],int n,int p,int x) {
        //lit it up
        if(dp[n][x]!=-1)return dp[n][x];
        int rl=0;
        for(int c:g[n]) {
            if(c==p)continue;
            rl+=helper(g,c,n,1);
        }
        if(!x)return dp[n][x]=1+rl;
        int rnl=0;
        if(x==1) {
            for(int c:g[n]) {
                if(c==p)continue;
                rnl+=helper(g,c,n,0);
            }
        }
        return dp[n][x]=min(1+rl,rnl);
    }
  public:
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        vector<int>g[N+1];
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        memset(dp,-1,sizeof(dp));
        return helper(g,1,0,1);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends