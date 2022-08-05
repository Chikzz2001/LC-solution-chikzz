#define ll long long int
class Solution {
    ll dp[5001][4][4][4];
    const int M=1e9+7;
    int N;
    int ways(int row,int col1,int col2,int col3)
    {
        if(row==N)return 1;
        
        if(dp[row][col1][col2][col3]!=-1)return dp[row][col1][col2][col3];
        
        ll res=0;
        for(int c1=0;c1<3;c1++)
        {
            if(c1!=col1)
            {
                for(int c2=0;c2<3;c2++)
                {
                    if(c2!=col2&&c2!=c1)
                    {
                        for(int c3=0;c3<3;c3++)
                        {
                            if(c3!=col3&&c3!=c2)
                            {
                                res=(res%M+ways(row+1,c1,c2,c3)%M)%M;
                            }
                        }
                    }
                }
            }
        }
        return dp[row][col1][col2][col3]=res;
    }
public:
    int numOfWays(int n) 
    {
        N=n;
        memset(dp,-1LL,sizeof(dp));
        return ways(0,3,3,3);
    }
};