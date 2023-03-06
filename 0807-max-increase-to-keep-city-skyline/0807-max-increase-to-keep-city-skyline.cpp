class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>r(n,0),c(m,0);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                r[i]=max(r[i],grid[i][j]);
                c[j]=max(c[j],grid[i][j]);
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                res+=min(r[i],c[j])-grid[i][j];
            }
        }
        
        return res;
    }
};