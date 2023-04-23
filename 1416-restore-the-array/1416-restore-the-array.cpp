#define ll long long
class Solution {
    vector<ll>dp;
    const int M=1e9+7;
    int N;
    ll helper(string &s,int k,int i) {
        if(i==N)return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i]=='0')return 0;
        ll sum=0,res=0;
        for(int j=i;j<N&&sum*10+(s[j]-'0')<=k;j++) {
            res=(res%M+helper(s,k,j+1)%M)%M;
            sum=sum*10+s[j]-'0';
        }
        return dp[i]=res;
    }
public:
    int numberOfArrays(string s, int k) {
        N=s.length();
        dp=vector<ll>(N,-1);
        return helper(s,k,0);
    }
};