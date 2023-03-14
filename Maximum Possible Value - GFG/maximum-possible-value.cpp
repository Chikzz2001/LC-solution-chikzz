//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        ll res=0;
        ll sum=0;
        int minn=1e9;
        for(int i=0;i<N;i++) {
            res+=1ll*A[i]*(B[i]/2)*2;
            sum+=1ll*(B[i]/2)*2;
            if(B[i]>1)minn=min(minn,A[i]);
        }
        
        if((sum/2)&1) {
            res-=2*minn;
        }
        return res;
    }
    /*
    8
     2 4 6 8 7 3
     4 10 2 4 2 8
    2-->1 sq 4-->2 sq 2-4 2-6 8-->1 sq 2-7 3-->2sq
    */
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends