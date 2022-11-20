#define ll long long int
class Solution {
    ll dp[1001][1001];
    set<char>p;
    const int M=1e9+7;
    int ml;
    ll helper(string &s,int k,int idx)
    {
        if(k==0)
        {
            return idx<s.length()?1:0;
        }
        if(idx>=s.length())return 0;
        
        if(dp[idx][k]!=-1LL)return dp[idx][k];
        ll res=0;
        if(!p.count(s[idx])&&(idx+1<s.length())&&p.count(s[idx+1]))
        {
            res=(res%M+helper(s,k-1,idx+ml)%M)%M;
        }
        res=(res%M+helper(s,k,idx+1)%M)%M;
        return dp[idx][k]=res;
    }
public:
    int beautifulPartitions(string s, int k, int minLength) {
        p.insert('2');p.insert('3');p.insert('5');p.insert('7');
        ml=minLength;
        if(!p.count(s[0])||p.count(s.back()))return 0;
        memset(dp,-1LL,sizeof(dp));
        return helper(s,k-1,ml-1);
    }
};