#define ll long long
class Solution {
    vector<ll>dp;
    ll helper(vector<vector<int>>& rides,int i) {
        if(i>=rides.size())return 0;
        
        if(dp[i]!=-1)return dp[i];
        //take
        int l=i+1,r=rides.size()-1;
        while(l<=r) {
            int m=l+(r-l)/2;
            if(rides[m][0]>=rides[i][1])r=m-1;
            else l=m+1;
        }
        ll op1=rides[i][1]-rides[i][0]+rides[i][2]+helper(rides,l);
        
        //not_take
        ll op2=helper(rides,i+1);
        
        return dp[i]=max(op1,op2);
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int N=rides.size();
        dp=vector<ll>(N,-1);
        sort(rides.begin(),rides.end());
        return helper(rides,0);
    }
};