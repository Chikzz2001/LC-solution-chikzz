class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int n=s.length();
        if(n!=t.length())return 0;
        vector<char>st(256,'#'),ts(256,'#');
        
        for(int i=0;i<n;i++)st[s[i]]=t[i];
        for(int i=0;i<n;i++)ts[t[i]]=s[i];
        
        for(int i=0;i<n;i++)
        {
            if(st[s[i]]!=t[i]||ts[t[i]]!=s[i])return 0;
        }
        return 1;
    }
};