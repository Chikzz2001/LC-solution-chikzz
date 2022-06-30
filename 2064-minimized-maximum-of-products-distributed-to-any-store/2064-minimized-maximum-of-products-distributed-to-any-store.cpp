class Solution {
    bool check(vector<int>& Q,int n,int max_Q)
    {
        int tot=0;
        for(auto &x:Q)
        {
            tot+=(x%max_Q?x/max_Q+1:x/max_Q);
        }
        return tot<=n;
    }
public:
    int minimizedMaximum(int n, vector<int>& Q) 
    {
        
        int lo=1,hi=*max_element(Q.begin(),Q.end()),res=-1;
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(Q,n,mid))
            {
                res=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        return res;
    }
};

