class Solution {
    int dp[501][501];
    int helper(vector<int>& presum,int i,int j,int &n)
    {
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int leftsum=0,rightsum=0,maxx=0;
        for(int k=i;k<j;k++)
        {
            leftsum=i==0?presum[k]:presum[k]-presum[i-1];
            rightsum=presum[j]-presum[k];
            
            if(leftsum>rightsum)
            {
                maxx=max(maxx,rightsum+helper(presum,k+1,j,n));
            }
            else if(leftsum<rightsum)
            {
               maxx=max(maxx,leftsum+helper(presum,i,k,n)); 
            }
            else
            {
                maxx=max({maxx,leftsum+helper(presum,i,k,n),rightsum+helper(presum,k+1,j,n)}); 
            }
        }
    
        return dp[i][j]=maxx;
    }
public:
    int stoneGameV(vector<int>& stoneValue) 
    {
        int n=stoneValue.size();
        vector<int>presum(n,0);
        
        presum[0]=stoneValue[0];
        
        for(int i=1;i<n;i++)
        {
            presum[i]=presum[i-1]+stoneValue[i];
        }
        
        memset(dp,-1,sizeof(dp));
        return helper(presum,0,n-1,n);
    }
};