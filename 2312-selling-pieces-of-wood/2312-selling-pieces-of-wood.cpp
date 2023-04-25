#define ll long long
class Solution {
    map<pair<int,int>,ll>mp;
    ll dp[201][201];
    ll helper(int i_len,int j_len) {
        if(i_len<=0||j_len<=0) {
            return 0;
        }
        
        if(dp[i_len][j_len]!=-1)return dp[i_len][j_len];
        ll maxx=mp.count({i_len,j_len})?mp[{i_len,j_len}]:0;
        
        for(int i=1;i<i_len;i++) {
            maxx=max(maxx,helper(i,j_len)+helper(i_len-i,j_len));
        }
        for(int j=1;j<j_len;j++) {
            maxx=max(maxx,helper(i_len,j)+helper(i_len,j_len-j));
        }
        return dp[i_len][j_len]=maxx;
    }
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        swap(n,m);
        
        memset(dp,-1,sizeof(dp));
        for(auto p:prices) {
            mp[{p[0],p[1]}]=p[2];
        }
        
        return helper(n,m);
    }
};