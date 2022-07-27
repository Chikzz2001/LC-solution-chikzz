class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int sum_of_leaves=accumulate(arr.begin(),arr.end(),0);
        
        int n=arr.size();
        int dp[n][n],maxx[n][n];
        
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=i+g;j<n;i++,j++)
            {
                if(g==0)dp[i][i]=arr[i],maxx[i][i]=arr[i];
            else if(g==1)maxx[i][i+1]=max(arr[i],arr[i+1]),dp[i][i+1]=arr[i]*arr[i+1]+arr[i]+arr[i+1];
                else
                {
                    int minn=1e9,ma=0;
                    for(int k=i;k<j;k++)
                    {
                        ma=max(ma,arr[k]);
                        minn=min(minn,dp[i][k]+(maxx[i][k]*maxx[k+1][j])+dp[k+1][j]);
                    }
                    dp[i][j]=minn;
                    maxx[i][j]=max(ma,arr[j]);
                }
            }
        }
        return dp[0][n-1]-sum_of_leaves;
    }
};

/*

6 2 4
12 8
6+6*8

*/