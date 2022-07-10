class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) 
    {
        sort(clips.begin(),clips.end());
        if(clips[0][0]!=0)return -1;
        int n=clips.size();
        int dp[n+1];
        int i=0;
        for(;i<n&&clips[i][0]==0;i++)
        {dp[i]=1;if(clips[i][1]>=time)return 1;}
        
        int res=n+2;
        for(;i<n;i++)
        {
            dp[i]=i+2;
            for(int j=i-1;j>=0;j--)
            {
                if(clips[j][1]>=clips[i][0])
                {
                    dp[i]=min(dp[i],1+dp[j]);
                }
            }
            if(dp[i]!=(i+2)&&clips[i][1]>=time)
                res=min(res,dp[i]);
        }
        
        return res==n+2?-1:res; 
    }
};