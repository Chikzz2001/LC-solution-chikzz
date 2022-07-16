#define ll long long int
class Solution {
    ll dp[51][51][51];
    const int M=1e9+7;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    
    bool invalid(int i,int j,int &n,int &m)
    {
        return !(i>=0&&j>=0&&i<n&&j<m);
    }
    
    ll helper(int i,int j,int &n,int &m,int moves)
    {
        if(invalid(i,j,n,m))
            return 1;
        
        if(moves==0)return 0;
        
        if(dp[i][j][moves]!=-1)
            return dp[i][j][moves];
        
        ll res=0;
        for(int k=0;k<4;k++)
        {
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            
            res=(res%M+helper(ni,nj,n,m,moves-1)%M)%M;
        }
        return dp[i][j][moves]=res%M;
    }
public:
    int findPaths(int m, int n, int maxMove, int sR, int sC) 
    {
        memset(dp,-1LL,sizeof(dp));
        return helper(sR,sC,m,n,maxMove)%M;
    }
};