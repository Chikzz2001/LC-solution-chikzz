//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int cb=0,ca=0;
        for(int i=0;i<30;i++)
        {
            if((1<<i)&b)cb++;
            if((1<<i)&a)ca++;
        }
        int x=0;
        if(ca>=cb)
        {
            for(int i=30;i>=0&&cb>0;i--)
            {
                if((1<<i)&a){x|=(1<<i);cb--;}
            }
        }
        else
        {
            x=a;
            cb-=ca;
            for(int i=0;i<30&&cb>0;i++)
            {
                if(!((1<<i)&a)){x|=(1<<i);cb--;}
            }
        }
        return x;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends