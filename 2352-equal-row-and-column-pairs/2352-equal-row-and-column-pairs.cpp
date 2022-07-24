class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int i=0,j=0;
        int n=grid.size();
        int res=0;
        map<vector<int>,int>r,c;
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
           for(int j=0;j<n;j++)
           {
               temp.push_back(grid[i][j]);
           }
            r[temp]++;
        }
        
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
           for(int j=0;j<n;j++)
           {
               temp.push_back(grid[j][i]);
           }
            c[temp]++;
        }
        
        for(auto &[x,y]:r)
        {
            if(c.count(x))res+=(y*c[x]);
        }
        return res;
    }
};