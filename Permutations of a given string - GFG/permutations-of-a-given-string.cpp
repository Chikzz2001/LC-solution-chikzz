// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    set<string>res;
    void permute(string &s,int idx)
    {
        if(idx==(int)s.length())
        {
            if(!res.count(s))
            res.insert(s);
            return;
        }
        
        for(int i=idx;i<(int)s.length();i++)
        {
               swap(s[i],s[idx]);
                permute(s,idx+1);
                swap(s[i],s[idx]); 
        }
    }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    permute(S,0);
		    vector<string>ans;
		    for(auto &x:res)ans.push_back(x);
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends