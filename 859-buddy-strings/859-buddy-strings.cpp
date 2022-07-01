class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        if(s.length()!=goal.length())return 0;
        if(s.length()==1)return 0;
        if(s==goal)
        {
            vector<int>f(26,0);
            for(auto &ch:s)
                f[ch-'a']++;
            for(int i=0;i<26;i++)
                if(f[i]>1)return 1;
            return 0;
        }
        else
        {
            char a,b;
            int c=0;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]!=goal[i])
                {
                    if(c==0)
                    a=s[i],b=goal[i];
                    else
                    {
                        if(c>1)return 0;
                        if(goal[i]!=a||s[i]!=b)
                            return 0;
                    }
                    c++;
                }
            }
            return c==2;
        }
    }
};