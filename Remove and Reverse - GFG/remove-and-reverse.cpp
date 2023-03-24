//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        map<char,int>m;
        for(auto x:S)m[x]++;
        
        int f=1;
        int n=S.length();
        int i=0,j=n-1;
        string s,ss;
        while(i<=j) {
            if(f) {
                if(i<=j&&m[S[i]]>1) {
                    m[S[i]]--;
                    i++;
                }
                else {
                    while(i<=j&&m[S[i]]==1) {
                    // cout<<"front "<<S[i]<<"\n";
                    s+=S[i];
                    m[S[i]]--;
                    i++;
                }
                if(i<=j) {
                    m[S[i]]--;
                    i++;
                }
                else break;
                }
            }
            else {
                if(i<=j&&m[S[j]]>1) {
                    m[S[j]]--;
                    j--;
                }
                else {
                    while(i<=j&&m[S[j]]==1) {
                        // cout<<"back "<<S[j]<<"\n";
                        ss+=S[j];
                        m[S[j]]--;
                        j--;
                    }
                    if(i<=j) {
                        m[S[j]]--;
                        j--;
                    }
                    else break;
                }
            }
            f^=1;
        }
        reverse(ss.begin(),ss.end());
        s+=ss;
        if(!f)reverse(s.begin(),s.end());
        return s;
    }
    //kldejsfkdfdhkdkrgherjkghudjfgdfvbhjdghktghdkjghbkdjbfb
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends