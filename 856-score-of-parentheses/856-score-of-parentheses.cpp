class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        int depth=-1;
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            depth++;
            else
            {
                if(s[i-1]=='(')
                res+=1<<depth;
                depth--;
            }
        }
        return res;
    }
};

/*

((())())
0 1 2 
1
*/