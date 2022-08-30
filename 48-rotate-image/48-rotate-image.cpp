class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
        for(auto &x:matrix)
        {
            reverse(x.begin(),x.end());
        }
        
        //for any ele (i,j)-->after transpose it goes to (j,i)-->and after reversing within row
        //it goes to (n-1-j,i)
        
        //so 90deg tranform of an ele--> (i,j)-->(n-1-j,i)
    }
};