class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        unordered_map<char,char>mp;
        unordered_map<char,char>mp1;
        for(string x:words)
        {
            if(x.length()!=pattern.length())continue;
            bool f=1;
            for(int i=0;i<x.length();i++)
            {
          if(mp.find(x[i])!=mp.end()&&mp[x[i]]!=pattern[i]){f=0;break;}
          if(mp1.find(pattern[i])!=mp1.end()&&mp1[pattern[i]]!=x[i]){f=0;break;}
                mp[x[i]]=pattern[i];
                mp1[pattern[i]]=x[i];
        }
            mp.clear();mp1.clear();
            if(f)ans.push_back(x);
        }
        return ans;
    }
};