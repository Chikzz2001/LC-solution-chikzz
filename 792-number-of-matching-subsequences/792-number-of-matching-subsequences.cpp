class Solution {
    unordered_map<string,bool>istrue;
    bool match(string &s,string t)
    {
        int sp=0,tp=0;
        while(sp<s.length()&&tp<t.length())
        {
            if(s[sp]==t[tp])
                tp++;
            sp++;
        }
        return tp==t.length();
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        int count=0;
        for(auto &w:words)
        {
            if(istrue.count(w))
            {
                count+=istrue[w];
                continue;
            }
            if(match(s,w))
            {
                istrue[w]=1;
                count++;
            }
            else
                istrue[w]=0;
        }
        return count;
    }
};