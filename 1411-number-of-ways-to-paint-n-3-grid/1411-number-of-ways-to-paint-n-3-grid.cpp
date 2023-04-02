class Solution {
    int dp[5001][4][4][4];
    const int M=1e9+7;
public:
    int numOfWays(int n) {
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                for(int k=0;k<4;k++)
                    if(i!=j&&j!=k)
                    dp[0][i][j][k]=1;
            }
        }
        
        for(int i=1;i<n;i++) {
            for(int a=0;a<3;a++) {
                for(int b=0;b<3;b++) {
                    for(int c=0;c<3;c++) {
                        if(a!=b&&b!=c) {
                            for(int d=0;d<3;d++) {
                                for(int e=0;e<3;e++) {
                                    for(int f=0;f<3;f++) {
                                        if(d!=e&&e!=f&&d!=a&&e!=b&&f!=c)dp[i][a][b][c]=(dp[i][a][b][c]%M+dp[i-1][d][e][f]%M)%M;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++) {
                    if(i!=j&&j!=k)
                    res=(res%M+dp[n-1][i][j][k]%M)%M;
                }
            }
        }
        return res;
    }
};