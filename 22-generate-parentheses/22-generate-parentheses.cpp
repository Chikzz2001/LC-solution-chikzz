class Solution {
    vector<string>res;
    string t;
    void dfs(int o,int c)
    {
        if(o==0&&c==0)
        {
            res.push_back(t);
            return;
        }
        if(o)
        {
            t+="(";
            dfs(o-1,c);
            t.pop_back();
        }
        if(c>o)
        {
            t+=")";
            dfs(o,c-1);
            t.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(n,n);
        return res;
    }
};