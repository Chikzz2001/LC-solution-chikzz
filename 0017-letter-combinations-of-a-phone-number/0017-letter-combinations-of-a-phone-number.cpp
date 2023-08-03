class Solution {
    vector<string>res;
    string t;
    void dfs(string& dig,int i,vector<string>& v)
    {
        if(i==dig.length())
        {
            res.push_back(t);
            return;
        }
        for(int j=0;j<v[dig[i]-'0'-2].length();j++)
        {
            t+=v[dig[i]-'0'-2][j];
            dfs(dig,i+1,v);
            t.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string dig) {
        if(dig.length()==0)return res;
        vector<string>v={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        dfs(dig,0,v);
        return res;
    }
};