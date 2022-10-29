class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        vector<int>res;
        for(int i=0;i<m;i++)
        {
            int p=i;
            bool f=1;
            for(int j=0;j<n;j++)
            {
                if(grid[j][p]==1)
                {
                    if(p==m-1||grid[j][p+1]==-1)
                    {f=0;break;}
                    else
                        p++;
                }
                else
                {
                    if(p==0||grid[j][p-1]==1)
                    {f=0;break;}
                    else
                        p--;
                }
            }
            if(f)res.push_back(p);
            else
                res.push_back(-1);
        }
        return res;
    }
};