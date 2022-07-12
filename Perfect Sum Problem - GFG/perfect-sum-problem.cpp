// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#define ll long long int
class Solution{
const int M=1e9+7;
vector<vector<ll>>dp;
int S;
ll helper(int arr[],int i,int sum,int &n)
{
    if(i==n)
    return sum==S?1:0;
    
    if(dp[i][sum]!=-1)
    return dp[i][sum];
    
    ll res1=0,res2=0;
    
    if(sum+arr[i]<=S)
    res1+=helper(arr,i+1,sum+arr[i],n);
    res2=helper(arr,i+1,sum,n);
    
    ll res=(res1%M+res2%M)%M;
    return dp[i][sum]=res;
}
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        dp=vector<vector<ll>>(n,vector<ll>(sum+1,-1));
        S=sum;
        return helper(arr,0,0,n)%M;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends