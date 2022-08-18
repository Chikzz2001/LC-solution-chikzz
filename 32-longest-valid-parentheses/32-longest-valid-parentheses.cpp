class Solution {
public:
    int longestValidParentheses(string s) 
    {
        //()(()
        // (()
        //00
        int n=s.length();
        int dp[n+1];
        dp[0]=0;
        stack<int>st;
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {st.push(i);dp[i+1]=0;}
            else
            {
                if(st.empty())
                    dp[i+1]=0;
                else
                {
                    int idx=st.top();
                    st.pop();
                    dp[i+1]=(i-idx+1)+dp[idx];
                }
            }
            res=max(res,dp[i+1]);
        }
        //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
        return res;
    }
};