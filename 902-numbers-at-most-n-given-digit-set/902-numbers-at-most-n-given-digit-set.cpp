#define ll long long int
class Solution {
    ll dp[11][2];
    ll helper(int i,string &s,vector<int>& digs,int bound)
    {
        if(i==s.length())
        return 1;
        
        if(dp[i][bound]!=-1)
            return dp[i][bound];
        
        int maxx=s[i]-'0';
        ll tot=0;
        
        int j;
        
        if(bound==0)
        {
            tot+=(digs.size()*helper(i+1,s,digs,0));
        }
        else
        {
            for(j=0;j<digs.size()&&digs[j]<maxx;j++)
            tot+=helper(i+1,s,digs,0);
        
            if(j<digs.size()&&digs[j]==maxx)
                tot+=helper(i+1,s,digs,1);
        }
        
        return dp[i][bound]=tot;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) 
    {
        string s=to_string(n);
        
        vector<int>digs;
        for(auto &d:digits)
            digs.push_back(stoi(d));
        
        memset(dp,-1,sizeof(dp));
        
        ll res=helper(0,s,digs,1);
        for(int i=1;i<s.length();i++)
            res+=helper(i,s,digs,0);
        
        return res;
    }
};

//_ _ _
//0 4 4
//    4

//16+