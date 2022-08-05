class Solution {
    long double dp[26][26][101];
    bool valid(int i,int j,int n)
    {
        return i>=0&&j>=0&&i<n&&j<n;
    }
    
    int dir[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
    long double dfs(int n,int i,int j,int k)
    {
        if(k==0)
        {
            return 1.0;
        }
        
        if(dp[i][j][k]!=-1.0)
            return dp[i][j][k];
        
        long double res=0.0;
        for(int l=0;l<8;l++)
        {
            int ni=i+dir[l][0];
            int nj=j+dir[l][1];
            
            if(valid(ni,nj,n))
            res+=dfs(n,ni,nj,k-1)/8.0;
        }
        
        return dp[i][j][k]=res;
    }
public:
    double knightProbability(int n, int k, int row, int column) 
    {
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                for(int l=0;l<101;l++)
                {
                    dp[i][j][l]=-1;
                }
            }
        }
        return dfs(n,row,column,k);
    }
};