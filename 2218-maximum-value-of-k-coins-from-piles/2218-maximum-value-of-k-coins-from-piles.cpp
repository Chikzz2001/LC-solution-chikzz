#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

class Solution 
{
    int dp[1001][2001];
    int helper(vector<vector<int>>& piles,int i,int k,int &n)
    {
        if(k==0)
            return 0;
        
        if(k<0||i==n)
            return -1e9;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int size=min(piles[i].size(),k);
        int maxx=helper(piles,i+1,k,n);
        int pre=0;
        for(int j=0;j<size;j++)
        {
            pre+=piles[i][j];
           maxx=max(maxx,pre+helper(piles,i+1,k-j-1,n)); 
        }
        
        return dp[i][k]=maxx;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n=piles.size();
        
        memset(dp,-1,sizeof(dp));
        return helper(piles,0,k,n);
    }
};