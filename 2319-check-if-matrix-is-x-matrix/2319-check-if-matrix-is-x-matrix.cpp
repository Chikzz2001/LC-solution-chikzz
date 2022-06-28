class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
     
        int n=grid.size();
        int i=0,j=0;
        
        while(i<n)
        {
            if(grid[i][j]==0)return 0;
            grid[i][j]=0;
            i++;j++;
        }
        
        i=0,j=n-1;
        while(i<n)
        {
            if((n&1)&&(i==n/2&&j==n/2))
            {i++;j--;continue;}
            if(grid[i][j]==0)return 0;
            grid[i][j]=0;
            i++;j--;
        }
 
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<n;l++)
            {
                if(grid[k][l]!=0)return 0;
            }
        }
        return 1;
    }
};