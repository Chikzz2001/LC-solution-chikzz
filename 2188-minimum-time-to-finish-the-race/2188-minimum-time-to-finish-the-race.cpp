#define ll long long
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
class Solution {
      
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) 
    {
        
        int n=tires.size();
        int len=0;
        vector<ll>store(numLaps,1e18);
        vector<int>dp(numLaps+1,INT_MAX);
        
        for(int i=0;i<n;i++)
        {
            ll streak=changeTime,p=1,r=tires[i][1],f=tires[i][0];
            
            for(int j=0;j<numLaps;j++)
            {
                streak+=f*p;
                
                if(f*p>=f+changeTime)
                    break;
                
                store[j]=min(store[j],streak);
                len=max(len,j+1);
                p*=r;
            }
        }
        
        dp[0]=0;
        
        for(int i=0;i<numLaps;i++)
        {
            for(int j=0;j<len&&(i-j)>=0;j++)
            {
                dp[i+1]=min(dp[i+1],dp[i-j]+store[j]);
            }
        }
        
        return dp[numLaps]-changeTime;
    }
};