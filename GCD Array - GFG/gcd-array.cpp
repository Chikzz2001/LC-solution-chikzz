//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
    // vector<int>pre;
    // int helper(vector<int>& arr,int i,int K,int N,vector<vector<int>>& dp)
    // {
    //     if(i==N)return 1;
    //     if(K==1)return pre[N-1]-(i?pre[i-1]:0);
    //     if(dp[i][K]!=-1)return dp[i][K];
        
    //     int s=0,res=1;
    //     for(int j=i;j<N;j++)
    //     {
    //         s+=arr[j];
    //         int a=helper(arr,j+1,K-1,N,dp);
    //         res=max(res,__gcd(s,a));
    //     }
    //     return dp[i][K]=res;
    // }
  public:
    int solve(int N, int K, vector<int> &arr) {
        // code here
        // vector<vector<int>>dp(N,vector<int>(K+1,-1));
        // pre=vector<int>(N);
        // pre[0]=arr[0];
        // for(int i=1;i<N;i++)pre[i]=arr[i]+pre[i-1];
        // return helper(arr,0,K,N,dp);
        int s=0;
        vector<int>f;
        for(int i=0;i<N;i++)s+=arr[i];
        for(int i=1;i*i<s;i++)
        {
            if(s%i==0){f.push_back(i);f.push_back(s/i);}
        }
        if(s%(int)(sqrt(s))==0)f.push_back((int)sqrt(s));
        sort(f.begin(),f.end());
        
        for(int i=f.size()-1;i>=0;i--)
        {
            int ss=0,p=0;
            for(int j=0;j<N;j++)
            {
                ss+=arr[j];
                if(ss%f[i]==0)
                {
                    ss=0;
                    p++;
                }
            }
            if(!ss&&p>=K)return f[i];
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends