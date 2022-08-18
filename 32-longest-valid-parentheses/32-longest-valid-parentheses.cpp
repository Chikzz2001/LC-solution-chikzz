class Solution {
public:
    int longestValidParentheses(string s) 
    {
        // //1 2 1
        // //-1 0 -1 0 -1 -2
        // map<int,int>m;
        // int i=0;
        // m[0]=-1;
        // int pre=0,res=0;
        // for(;i<s.length();i++)
        // {
        //     pre+=(s[i]=='('?1:-1);
        //     if(pre<0)
        //     {
        //         m.clear();
        //         m[0]=i;
        //         pre=0;
        //         continue;
        //     }
        //     if(m.count(pre))
        //     {
        //         res=max(res,i-m[pre]);
        //     }
        //     if(!m.count(pre))
        //         m[pre]=i;
        // }
        // return res;
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