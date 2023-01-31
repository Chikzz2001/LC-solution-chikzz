//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

bool check(string &A,string &B) {
    string st=A+"#"+B;
    
       int n=st.length();
        int lps[n];
        lps[0]=0;
    
        int len=0;
        for(int i=1;i<n;)
        {
            if(st[i]==st[len])
            {
                len++;
                lps[i]=len;
                if(lps[i]==(int)A.length())return 1;
                i++;
            }
            else
            {
                if(len>0)
                len=lps[len-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        return 0;

}
class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        int n=A.length(),m=B.length();
        if(m<=n) {
            if(A==B)return 1;
            string s=A+A;
            if(check(B,s))return 2;
            return -1;
        }
        int x=m/n,y=m/n+1;
        string ss;
        for(int i=0;i<x;i++)ss+=A;
        int i=0,j=0;
        n=ss.length();
        if(check(B,ss))return x;
        i=0,j=0;
        ss+=A,n=ss.length();
        if(check(B,ss))return y;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends