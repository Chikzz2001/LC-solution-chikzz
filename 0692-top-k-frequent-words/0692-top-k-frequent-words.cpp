class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string,int>m;
        
        for(auto &w:words)
        m[w]++;
        
        map<int,vector<string>,greater<int>>buckets;
        
        for(auto &[s,count]:m)
        {
            buckets[count].push_back(s);
        }
        
        vector<string>res;
        for(auto &[freq,words]:buckets)
        {
            for(auto &w:words)
            {
                if(!k)return res;
                res.push_back(w);
                k--;
            }
        }
        
        return res;
    }
};