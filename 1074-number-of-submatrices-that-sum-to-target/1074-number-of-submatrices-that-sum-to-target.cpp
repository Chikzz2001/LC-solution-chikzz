class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int n=matrix.size(),m=matrix[0].size();
        int pre[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)pre[i][j]=matrix[i][j];
                else pre[i][j]=pre[i][j-1]+matrix[i][j];
            }
        }
        
        
        int res=0;
        for(int c1=0;c1<m;c1++)
        {
            for(int c2=c1;c2<m;c2++)
            {
                unordered_map<int,int>pre_occurence;
                pre_occurence[0]=1;
                int prefix_sum=0;
                for(int r=0;r<n;r++)
                {
                    int sum=pre[r][c2]-(c1==0?0:pre[r][c1-1]);
                    prefix_sum+=sum;
                    if(pre_occurence.count(prefix_sum-target))
                        res+=pre_occurence[prefix_sum-target];
                    pre_occurence[prefix_sum]++;
                }
            }
        }
        
        return res;
    }
};