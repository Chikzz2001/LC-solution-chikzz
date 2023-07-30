class Solution {
    int dp[101][2][2][11];
    const int M=1e9+7;
    int helper(string &a,int i,int lz,int bound,int last_dig) {
        if(i==a.size())return 1;
        
        if(dp[i][lz][bound][last_dig]!=-1)return dp[i][lz][bound][last_dig];
        
        int maxx=bound?a[i]-'0':9;
        
        int res=0;
        
        if(lz) {
            for(int j=0;j<=maxx;j++) {
            res=(res%M+helper(a,i+1,lz&(j==0),bound&(j==maxx),j)%M)%M;
            }
        }
        else {
            if((last_dig-1)>=0&&(last_dig-1)<=maxx)res=(res%M+helper(a,i+1,lz&((last_dig-1)==0),bound&((last_dig-1)==maxx),(last_dig-1))%M)%M;
            if(last_dig+1<=maxx)res=(res%M+helper(a,i+1,lz&((last_dig+1)==0),bound&((last_dig+1)==maxx),(last_dig+1))%M)%M;
        }
            
        return dp[i][lz][bound][last_dig]=res;
    }
public:
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        int f=1;
        for(int i=1;i<low.length();i++) {
            if(abs(low[i]-low[i-1])!=1){f=0;break;}
        }
        int res=helper(high,0,1,1,10);
        // cout<<res<<"\n";
        memset(dp,-1,sizeof(dp));
        res=(res-helper(low,0,1,1,10)+M)%M;
        // cout<<res<<"\n";
        return (res+f)%M;
    }
};