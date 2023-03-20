//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        if(D*9<=S)return "-1";
        string s(D,'0');
        s[0]='1';
        S--;
        for(int i=D-1;i>=0;i--) {
            if(S>=9){s[i]='9';S-=9;}
            else {
                s[i]=s[i]+S;
                S=0;break;
            }
        }
    
        // cout<<s<<"\n";
        for(int i=D-2;i>=0;i--) {
            if(s[i+1]>s[i]) {
                s[i]++;
                s[i+1]--;
                break;
            }
        }
        return s;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends