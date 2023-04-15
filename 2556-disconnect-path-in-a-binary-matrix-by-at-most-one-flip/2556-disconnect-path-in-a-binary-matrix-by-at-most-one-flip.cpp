#define ll long long int
class Solution {
    const int M=1000004249;
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        ll dp1[n][m],dp2[n][m];
        dp1[0][0]=1,dp2[n-1][m-1]=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0&&j==0)continue;
                if(grid[i][j]==1)dp1[i][j]=((i?dp1[i-1][j]%M:0)+(j?dp1[i][j-1]%M:0))%M;
                else dp1[i][j]=0;
            }
        }
        
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(i==n-1&&j==m-1)continue;
                if(grid[i][j]==1)dp2[i][j]=((i!=n-1?dp2[i+1][j]%M:0)+(j!=m-1?dp2[i][j+1]%M:0))%M;
                else dp2[i][j]=0;
            }
        }
       
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         cout<<dp1[i][j]<<","<<dp2[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        if(dp1[n-1][m-1]==0)return 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((i==0&&j==0)||(i==n-1&&j==m-1))continue;
                if((dp1[i][j]%M*dp2[i][j]%M)%M==dp1[n-1][m-1])return 1;
            }
        }
        
        return 0;
        
    }
};