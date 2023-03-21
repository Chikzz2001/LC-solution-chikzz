//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution{   
public:
    long long solve(int X,int Y,string S){
      ll res=0;
      int n=S.length();
      vector<int>v(n,0);
      if(X>Y) {
          stack<int>s;
          for(int i=0;i<n;i++) {
              if(S[i]=='r') {
                  if(s.size()&&S[s.top()]=='p') {
                      v[i]=1;
                      v[s.top()]=1;
                      s.pop();
                      res+=X;
                  }
                  else s.push(i);
              }
              else s.push(i);
          }
          while(!s.empty())s.pop();
          for(int i=0;i<n;i++) {
              if(v[i]==1)continue;
              if(S[i]=='p') {
                  if(s.size()&&S[s.top()]=='r') {
                      res+=Y;
                      s.pop();
                  }
                  else s.push(i);
              }
              else s.push(i);
          }
      }
      else {
          stack<int>s;
          for(int i=0;i<n;i++) {
              if(S[i]=='p') {
                  if(s.size()&&S[s.top()]=='r') {
                      v[i]=1;
                      v[s.top()]=1;
                      s.pop();
                      res+=Y;
                  }
                  else s.push(i);
              }
              else s.push(i);
          }
          while(!s.empty())s.pop();
          for(int i=0;i<n;i++) {
              if(v[i]==1)continue;
              if(S[i]=='r') {
                  if(s.size()&&S[s.top()]=='p') {
                      res+=X;
                      s.pop();
                  }
                  else s.push(i);
              }
              else s.push(i);
          }
      }
      return res;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends