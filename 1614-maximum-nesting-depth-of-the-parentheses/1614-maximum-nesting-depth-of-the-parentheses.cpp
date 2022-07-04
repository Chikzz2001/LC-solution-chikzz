class Solution {
public:
    int maxDepth(string s) 
    {
        int depth=0,res=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                depth++,res=max(res,depth);
            else if(s[i]==')')
                depth--;
        }
        return res;
    }
};