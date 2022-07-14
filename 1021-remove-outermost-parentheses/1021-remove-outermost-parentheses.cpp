class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        stack<int>st;
        string res;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                if(st.size()==1)
                    res+=s.substr(st.top()+1,i-st.top()-1);
                st.pop();
            }
        }
        return res;
    }
};