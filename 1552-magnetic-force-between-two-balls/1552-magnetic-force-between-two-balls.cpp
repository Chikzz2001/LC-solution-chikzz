class Solution {
    bool stable(vector<int>& P,int m,int min_force)
    {
        m--;
        int curr=P[0];
        for(int i=1;i<P.size();i++)
        {
            if(P[i]-curr>=min_force)
            {
                m--;
                curr=P[i];
            }
            if(m==0)return 1;
        }
        return 0;
    }
public:
    int maxDistance(vector<int>& P, int m) {
        int n=P.size();
        
        sort(P.begin(),P.end());
        int lo=1e9,hi=P[n-1]-P[0],res;
        
        for(int i=0;i<n-1;i++)
            lo=min(lo,P[i+1]-P[i]);
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(stable(P,m,mid))
            {
                res=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        return res;
    }
};


/*
22 57 74 79

*/