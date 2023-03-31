#define ll long long
class Solution {
    int pre[52][52];
    const int M=1e9+7;
    ll dp[52][52][11];
    int n,m;
    ll helper(int lui,int luj,int k) {
        if(k==1) {
            int apples=pre[n][m]+pre[lui-1][luj-1]-pre[n][luj-1]-pre[lui-1][m];
            if(apples>0)return 1;
            return 0;
        }
        if(dp[lui][luj][k]!=-1)return dp[lui][luj][k];
        ll res=0;
        for(int i=lui;i<n;i++) {
            int apples=pre[i][m]+pre[lui-1][luj-1]-pre[i][luj-1]-pre[lui-1][m];
            if(apples>0) {
                res=(res%M+helper(i+1,luj,k-1)%M)%M;
            }
        }
        for(int j=luj;j<m;j++) {
            int apples=pre[n][j]+pre[lui-1][luj-1]-pre[n][luj-1]-pre[lui-1][j];
            if(apples>0) {
                res=(res%M+helper(lui,j+1,k-1)%M)%M;
            }
        }
        return dp[lui][luj][k]=res;
    }
public:
    int ways(vector<string>& pizza, int k) {
        n=pizza.size(),m=pizza[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                pre[i+1][j+1]=(pizza[i][j]=='.'?0:1)+pre[i][j+1]+pre[i+1][j]-pre[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        // cout<<pre[n][m];
        return helper(1,1,k);
    }
};