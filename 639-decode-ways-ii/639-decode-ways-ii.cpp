#define ll long long int
class Solution {
    const int M=1e9+7;
    ll dp[100001][5];
    ll ways(string &s,int i,int &n)
    {
        if(i==n)
            return 1;
        
        ll one=0,two=0;
        
        if(s[i]=='0')
        {
            return dp[i][0]=0;
        }
        else if(s[i]=='*')
        {
            if(dp[i][4]!=-1)
                return dp[i][4];
            ll tot_ways=0;
            s[i]='1';tot_ways+=ways(s,i,n);
            s[i]='2';tot_ways+=ways(s,i,n);
            s[i]='*';
            tot_ways+=(7*ways(s,i+1,n))%M;
            return dp[i][4]=(tot_ways)%M;
        }
        else
        {
            if(s[i]<='2')
            {
                if(dp[i][s[i]-'0']!=-1)
                    return dp[i][s[i]-'0'];
            }
            else
            {
                if(dp[i][3]!=-1)
                    return dp[i][3];
            }
            one+=ways(s,i+1,n);
            if(i<n-1)
            {
                if(s[i]=='1')
                {
                    if(s[i+1]=='*')
                        two+=(9*ways(s,i+2,n))%M;
                    else
                        two+=(ways(s,i+2,n))%M;
                }
                else if(s[i]=='2')
                {
                    if(s[i+1]=='*')
                        two+=(6*ways(s,i+2,n))%M;
                    else if(s[i+1]<='6')
                        two+=(ways(s,i+2,n))%M;
                }
            }
        }
        
        if(s[i]<='2')
        return dp[i][s[i]-'0']=(one+two)%M;
        else
            return dp[i][3]=(one+two)%M;
    }
public:
    int numDecodings(string s) 
    {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        ll res=ways(s,0,n)%M;
        return res;
    }
};
