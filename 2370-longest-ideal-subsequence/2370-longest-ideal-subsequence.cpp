class Solution {
public:
    int longestIdealString(string s, int k) 
    {
        int n=s.length();
        int dp[26]={0};
        dp[s[0]-'a']=1;
        for(int i=1;i<n;i++)
        {
            int temp=1;
            for(int j=max(0,s[i]-'a'-k);j<min(s[i]-'a'+k+1,26);j++)
            {
                temp=max(temp,1+dp[j]);
            }
            dp[s[i]-'a']=temp;
        }
        
        int res=0;
        for(int i=0;i<26;i++)
        {
            //cout<<dp[i]<<" ";
            res=max(res,dp[i]);
        }
            
        return res;
    }
};