class Solution {
    long long dp[100001];
    long long find(vector<vector<int>>& v,int i)
    {
        if(i>=v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        long long not_taken=find(v,i+1);
        long long taken=v[i][0]+find(v,i+v[i][1]+1);
        return dp[i]=max(not_taken,taken);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return find(questions,0);
    }
};