#define ll long long int
class Solution {
    map<ll,ll>dp[1001];
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),res=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ll x=(dp[j].count(1LL*nums[i]-1LL*nums[j])?dp[j][1LL*nums[i]-1LL*nums[j]]:0LL);
                dp[i][1LL*nums[i]-1LL*nums[j]]+=(x+1);
                res+=x;
            }
        }
        return res;
    }
};

/*
2 4 6 8

0 
dp[1][2]=1;
dp[2][4]=1;
dp[2][2]=2;
dp[3][6]=1;
dp[3][4]=2;
dp[3][2]=3;
ans-->dp[3][2]+dp[3][4]+dp[3][6]

[2,4,6,8,10]
1,2=2
2,4=2 2,2=3 -->1
3,6=2 3,4=2 3,2=4 -->1

*/