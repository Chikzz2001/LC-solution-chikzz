class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty()||st.top()!=s[i])
                st.push(s[i]);
            else
                st.pop();
        }
        vector<char>ans;
        while(!st.empty())
        {ans.push_back(st.top());
        st.pop();
        }
        string ss="";
        for(int i=ans.size()-1;i>=0;i--)
            ss+=ans[i];
        return ss;
    }
};