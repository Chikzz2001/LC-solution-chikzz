class Solution {
    int dp[11][2][2][10][10][20];
    int K;
    int helper(string &s,int i,int lz,int bound,int odd,int even,int rem) {
        if(i==s.length()) {
            if(lz)return 0;
            if(odd==even&&rem==0)return 1;
            return 0;
        }
        
        if(dp[i][lz][bound][odd][even][rem]!=-1)return dp[i][lz][bound][odd][even][rem];
        
        int maxx=bound?s[i]-'0':9;

        int tot=0;
        for(int j=0;j<=maxx;j++) {
            if(j==0) {
                if(lz)
                tot+=helper(s,i+1,1,bound&(j==maxx),odd,even,rem);
                else
                    tot+=helper(s,i+1,0,bound&(j==maxx),odd,even+1,(rem*10)%K);
            }
            else {
                tot+=helper(s,i+1,0,bound&(j==maxx),odd+(j%2),even+(1-j%2),(rem*10+j)%K);
            }
        }
        
        return dp[i][lz][bound][odd][even][rem]=tot;
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string a=to_string(low);
        string b=to_string(high);
        K=k;
        int f=0;
        int cnt=0;
        for(int i=0;i<a.length();i++) {
            if((a[i]-'0')&1)cnt++;
            else cnt--;
        }
        if(cnt==0&&low%k==0)f=1;
       
        memset(dp,-1,sizeof(dp));
        
        int res=helper(b,0,1,1,0,0,0);
        
        memset(dp,-1,sizeof(dp));
        res-=helper(a,0,1,1,0,0,0);
        return res+f;
    }
};