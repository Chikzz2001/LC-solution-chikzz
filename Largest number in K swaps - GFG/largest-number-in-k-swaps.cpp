// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
        void solve(string& str, int n, string& result, int k, int i){
        result = max(result, str);
        
        // base case
        if(i == n or k == 0){
            return;
        }
        
        /* 1. Find the largest char from i to n */
        char maxchar = str[i];
        for(int j=i+1; j<n; j++){
            maxchar = max(maxchar, str[j]);
        }
        
        /* 2. Do swapping with all str[i] and str[j] pairs such that str[j] == maxchar, we are doing swapping with all str[j] == maxchar because we do not know which swapping will lead us to the optimal answer...
        */
        if(maxchar > str[i]){
            for(int j=i+1; j<n; j++){
                if(str[j] == maxchar){
                    swap(str[i], str[j]);
                    solve(str, n, result, k-1, i+1);
                    swap(str[i], str[j]);
                }
            }
        }
        else{
            solve(str, n, result, k, i+1);
        }
    }

    string findMaximumNum(string str, int k)
    {
       // code here.
    //   int p=0;
    // priority_queue<pair<char,int>>pq;
    //     for(int j=0;j<str.length();j++)
    //   {
    //       pq.push({str[j],j});
    //   }
    //   while(pq.size()&&k>0)
    //   {
    //       pair<char,int>P=pq.top();pq.pop();
    //       if(P.second<p)
    //       continue;
    //       if(str[p]>=str[P.second])
    //       {p++;pq.push(P);continue;}
    //       cout<<p<<" "<<P.second<<"\n";
    //       swap(str[p++],str[P.second]);
    //       k--;
    //       if(P.second>=p&&str[P.second]>=str[p])
    //       pq.push({str[P.second],P.second});
    //   return str;
    // }
     int n = str.size();
        string result = str;
        
        solve(str, n, result, k, 0);
        
        return result;
      }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends