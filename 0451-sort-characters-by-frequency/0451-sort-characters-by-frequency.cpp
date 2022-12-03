class Solution {
public:
    string frequencySort(string s) {
        map<char,int>freq;
        int m=0;
        for(auto &c:s)
        {freq[c]++;m=max(m,freq[c]);}
        
        string st="";
        
        map<int,vector<char>>mp;
        for(auto &x:freq)
            mp[x.second].push_back(x.first);
        
        for(auto it=mp.rbegin();it!=mp.rend();it++)
        {
            int f=(*it).first;
            for(auto &x:(*it).second)
            st.append(f,x);
        }
        return st;
    }
};