#define ll long long int
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
       int n=points.size(),m=points[0].size();
        
        ll dp[m];
        
        for(int i=0;i<m;i++)
            dp[i]=points[0][i];
        
        for(int i=0;i<n-1;i++)
        {
            ll temp[m];
            ll l[m],r[m];
            
            l[0]=dp[0],r[m-1]=dp[m-1];
            for(int j=1;j<m;j++)
                l[j]=max(l[j-1]-1,dp[j]);
            for(int j=m-2;j>=0;j--)
                r[j]=max(r[j+1]-1,dp[j]);
            
            for(int j=0;j<m;j++)
            {
                temp[j]=points[i+1][j]+max(l[j],r[j]);
            }
            for(int i=0;i<m;i++)
                dp[i]=temp[i];
        }
        
        ll maxx=0;
        for(int i=0;i<m;i++)
            maxx=max(maxx,dp[i]);
        
        return maxx;
    }
};