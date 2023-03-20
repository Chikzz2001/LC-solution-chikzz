//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        queue<pair<int,int>>Q;
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(grid[i][j]=='X')Q.push({i,j});
            }
        }
        
        vector<vector<int>>vis(N,vector<int>(M,0));
        int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
        int steps=0;
        while(!Q.empty()) {
            int sz=Q.size();
            while(sz--) {
                pair<int,int>P=Q.front();Q.pop();
                int i=P.first;
                int j=P.second;
                for(int k=0;k<4;k++) {
                    int ni=i+dir[k][0];
                    int nj=j+dir[k][1];
                    if(ni>=0&&nj>=0&&ni<N&&nj<M&&!vis[ni][nj]) {
                        if(grid[ni][nj]=='Y')return steps+1;
                        vis[ni][nj]=1;
                        Q.push({ni,nj});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends