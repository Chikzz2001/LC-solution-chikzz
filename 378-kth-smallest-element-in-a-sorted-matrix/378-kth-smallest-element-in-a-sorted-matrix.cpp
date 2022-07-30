class Solution {
    int find_less_equal(vector<vector<int>>& matrix,int val,int n)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][n-1]<=val)
            {cnt+=n;continue;}
            else if(matrix[i][0]>val)
                break;
            else
            {
                int l=0,h=n-1;
                while(l<=h)
                {
                    int m=l+(h-l)/2;
                    if(matrix[i][m]>val)
                        h=m-1;
                    else
                        l=m+1;
                }
                cnt+=l;
            }
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int lo=matrix[0][0],hi=matrix[n-1][n-1];
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            int lessEq=find_less_equal(matrix,mid,n);
            
            //cout<<mid<<" "<<lessEq<<"\n";
            if(lessEq>=k)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return lo;
            
    }
};



/*


*/