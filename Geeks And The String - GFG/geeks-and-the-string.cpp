//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char>st;
        for(char ch:s)
        {
            st.push(ch);
           
                int c=0;
                while(st.size()&&st.top()==ch)
                st.pop(),c++;
                if(c&1)
                st.push(ch);
            
        }
        if(!st.size())return "-1";
        string res;
        while(st.size())res+=st.top(),st.pop();
        reverse(res.begin(),res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends