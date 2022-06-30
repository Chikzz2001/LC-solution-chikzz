#define ll long long
class Solution {
public:
    string stoneGameIII(vector<int>& s) {
       
        int n=s.size();
        ll dp[n+1];
        
        //dp[i]-->stores max value that a person can obtain if he has to start from ith idx
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=-1e9;
            ll take=0;
            for(int j=i;j<min(n,i+3);j++)
            {
                take+=s[j];
                dp[i]=max(dp[i],take-dp[j+1]);
            }
        }
    
        return dp[0]>0?"Alice":dp[0]==0?"Tie":"Bob";
    }
};
