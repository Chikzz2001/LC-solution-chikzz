#define ll long long
class Solution {
    ll dp[500001];
    int help(int i,vector<int>& s)
    {
        if(i>=s.size())return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        ll maxx=-1e9;
        ll take=0;
        for(int j=i;j<min((int)s.size(),i+3);j++)
        {
            take+=s[j];
            maxx=max(maxx,take-help(j+1,s));
        }
        return dp[i]=maxx;
    }
public:
    string stoneGameIII(vector<int>& s) {
        
        long long sum=0;
        for(auto &x:s)sum+=x;
        
        memset(dp,-1,sizeof(dp));
        
        long long diff=help(0,s);
        //for(int i=0;i<s.size();i++)cout<<dp[i]<<" ";
        return diff>0?"Alice":diff==0?"Tie":"Bob";
    }
};

/*
 1-(2-(3-7))
 1-(2+3-7)
 1-(2+3+7)
 1+2-(3-7)
 1+2-(3+7)
 1+2+3-7
*/