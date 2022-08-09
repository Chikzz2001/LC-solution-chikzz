class Solution {
    set<string>S;
    int helper(string &s,int i)
    {
        if(i==s.length())
            return S.size();
        
        int res=0;
        string st;
        for(int j=i;j<s.length();j++)
        {
            st+=s[j];
            if(!S.count(st))
            {
                S.insert(st);
                res=max(res,helper(s,j+1));
                S.erase(st);
            }
        }
        return res;
    }
public:
    int maxUniqueSplit(string s) {
        return helper(s,0);
    }
};