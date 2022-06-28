class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int>freq(26,0);
         int maxx=0;
        for(auto &ch:s)
        {
            freq[ch-'a']++;
            maxx=max(freq[ch-'a'],maxx);
        }
        
        vector<int>v(maxx+1,0);
        for(auto &x:freq)
        {
            v[x]++;
        }
        
        int res=0;
        for(int i=v.size()-1;i>0;i--)
        {
            if(!v[i])continue;
            res+=(v[i]-1);
            v[i-1]+=(v[i]-1);
        }
        
        return res;
    }
};
