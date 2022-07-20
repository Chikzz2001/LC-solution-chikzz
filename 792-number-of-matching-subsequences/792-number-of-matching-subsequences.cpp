class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        vector<set<int>>v(26);
        int n=words.size();
        vector<int>len(n,0);
        for(int i=0;i<n;i++)
        {
            v[words[i][0]-'a'].insert(i);
        }
        
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            set<int>temp=v[s[i]-'a'];
            for(auto &it:temp)
            {
                len[it]++;
                if(len[it]==words[it].length())
                {
                    v[words[it][len[it]-1]-'a'].erase(it);
                    res++;
                }
                else
                {
                    if(words[it][len[it]]!=words[it][len[it]-1])
                    {
                        v[words[it][len[it]-1]-'a'].erase(it);
                        v[words[it][len[it]]-'a'].insert(it);
                    }
                }
            }
        }
        return res;
    }
};