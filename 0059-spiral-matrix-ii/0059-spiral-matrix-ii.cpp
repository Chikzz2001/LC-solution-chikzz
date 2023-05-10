class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>>res(n,vector<int>(n));
        int c=1;
        
        int i=0,j=n-1;
        while(i<=n/2&&j>=n/2)
        {
            for(int k=n-1-j;k<=j;k++)
            {
                res[i][k]=c++;
            }
            
            for(int k=i+1;k<=n-1-i;k++)
            {
                res[k][j]=c++;
            }
            
            for(int k=j-1;k>=n-1-j;k--)
            {
                res[n-1-i][k]=c++;
            }
            
            for(int k=n-2-i;k>i;k--)
            {
                res[k][n-1-j]=c++;
            }
            i++;
            j--;
        }
        return res;
    }
};