class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        int n=mat.size(),m=mat[0].size();
        map<int,int>idx;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i-j].push_back(mat[i][j]);
                idx[i-j]=0;
            }
        }
        
        for(auto &[x,y]:mp)
        {
            sort(y.begin(),y.end());
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j]=mp[i-j][idx[i-j]++];
            }
        }
        return mat;
    }
};