//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        // code here
        //3 3 3 
        vector<int>m(k,0);
        sort(arr,arr+n);
        long long res=0;
        for(int i=0;i<n;i++)
        {
            arr[i]%=k;
            res+=1LL*m[arr[i]];
            m[arr[i]]++;
        }
        return res;
        //(a,b)-->ordered b-a>0
        //(b-a)%k=0-->(b%k-a%k)%k=0 b%k=a%k
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends