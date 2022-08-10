class Solution {
public:
    long long numberOfWays(string s) {
        unordered_map<int,pair<int,int>>mp;
        
        int cz=0;
        for(int i=0;i<s.length();i++)
        {
            mp[i].first=cz;
            if(s[i]=='0')
                cz++;
        }
        cz=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            mp[i].second=cz;
            if(s[i]=='0')
                cz++;
        }
        
        long long res=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                res+=(i-mp[i].first)*(s.length()-(i+1)-mp[i].second);
            }
            else
            {
                res+=(mp[i].first)*mp[i].second;
            }
        }
        
        return res;
    }
};