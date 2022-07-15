class Solution {
public:
    bool canChange(string start, string target) 
    {
        string s,e;
        for(int i=0;i<start.length();i++)
        {
            if(start[i]!='_')s+=start[i];
            if(target[i]!='_')e+=target[i];
        }
        if(s!=e)return 0;
        
        vector<int>ss,ee;
        for(int i=0;i<start.length();i++)
        {
            if(start[i]!='_')ss.push_back(i);
            if(target[i]!='_')ee.push_back(i);
        }
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='L')
            {
                if(ss[i]<ee[i])return 0;
            }
            else
            {
                if(ss[i]>ee[i])return 0;
            }
        }
        return 1;
    }
};