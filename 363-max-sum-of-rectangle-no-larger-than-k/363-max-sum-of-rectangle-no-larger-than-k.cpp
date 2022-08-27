class Solution {
    
    //WE CANNOT APPLY KADANE WHEN THERE IS A BOUND TO THE SUM WE CAN HAVE
    //CUZ THE LOGIC OF KADANE IS WE SPLIT THE ARRAY AND START OVER AGAIN WHENEVER WE GET A NEGATIVE SUM
    //CUZ (NEG SUM)+(SUM OF NEXT SUBARRAY)<SUM OF NEXT SUBARRAY
    
    //but here it fails
    //[[2,2,-1]],k=3  we have to cossider entire subarray
    //[[2,2,-1]],k=0  just last element
    //[[2,1,-1]],k=0 last two elements
    //we do not get a generalised logic to partition the array at any point
    
    int max_sum_subarray_no_greater_than_k(vector<int> v,int &k)
    {
        int res=-1e9;
       for(int i=0;i<v.size();i++)
       {
           int sum=0;
           for(int j=i;j<v.size();j++)
           {
               sum+=v[j];
               if(sum<=k)
                   res=max(res,sum);
           }
       }
        
        return res;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int n=matrix.size(),m=matrix[0].size();
        
        int maxx=-1e9;
        for(int i=0;i<n;i++)
        {
            vector<int>temp_array(m,0);
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                temp_array[k]+=matrix[j][k];

                int res=max_sum_subarray_no_greater_than_k(temp_array,k);
                //cout<<res<<"\n";
                    maxx=max(maxx,res);
            }
        }
        
        return maxx;
    }
};