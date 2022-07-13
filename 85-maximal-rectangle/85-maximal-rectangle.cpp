class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>A(n,vector<int>(m,0));
        for(int j=0;j<m;j++)A[0][j]=matrix[0][j]=='1'?1:0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        A[i][j]=matrix[i][j]=='1'?1+A[i-1][j]:0;
    }
    
    int res=0;
    for(int i=0;i<n;i++)
    {
        int ns[m],ps[m];
        stack<int>st;
        for(int j=0;j<m;j++)
        {
            while(!st.empty()&&A[i][st.top()]>=A[i][j])
            st.pop();
            int push=st.empty()?-1:st.top();
            ps[j]=push;
            st.push(j);
        }
        while(!st.empty())st.pop();
        for(int j=m-1;j>=0;j--)
        {
            while(!st.empty()&&A[i][st.top()]>=A[i][j])
            st.pop();
            int push=st.empty()?m:st.top();
            ns[j]=push;
            st.push(j);
        }
        for(int j=0;j<m;j++)
        res=max(res,A[i][j]*(ns[j]-ps[j]-1));
    }
    return res;
    }
};