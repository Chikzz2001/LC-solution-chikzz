class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
    {
        vector<vector<bool>>m(256,vector<bool>(256,0));
        for(auto &mp:mappings)
        m[mp[0]][mp[1]]=1;
        
        for(auto &ch:sub)
            m[ch][ch]=1;
        
        int n1=s.length(),n2=sub.length();
        for(int i=0;i<=n1-n2;i++)
        {
            bool f=1;
            for(int j=i;j<i+n2;j++)
            {
                if(!m[sub[j-i]][s[j]])
                {
                    f=0;
                    break;
                }
            }
            if(f)return 1;
        }
        return 0;
    }
};