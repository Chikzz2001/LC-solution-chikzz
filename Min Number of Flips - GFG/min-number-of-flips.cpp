// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int count(string S)
{
    int n=S.length(),c=0;
    for(int i=1;i<n;i++)
    {
        if(S[i]==S[i-1])
        {c++;S[i]='0'+(1-(S[i-1]-'0'));}
    }
    return c;
}
int count2(string S)
{
    int n=S.length(),c=0;
    for(int i=n-2;i>=0;i--)
    {
        if(S[i]==S[i+1])
        {c++;S[i]='0'+(1-(S[i+1]-'0'));}
    }
    return c;
}
int minFlips (string S)
{
    // your code here
    int minn=1e9,n=S.length();
    minn=min(minn,count(S));
    S[0]='0'+(1-(S[0]-'0'));
    minn=min(minn,1+count(S));
    S[0]='0'+(1-(S[0]-'0'));
    minn=min(minn,count2(S));
    S[n-1]='0'+(1-(S[n-1]-'0'));
    minn=min(minn,1+count2(S));
    return minn;
}