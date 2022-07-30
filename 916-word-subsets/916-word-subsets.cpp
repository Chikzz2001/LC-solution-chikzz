class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>freq(26,0);
        for(auto &x:words2)
        {
            vector<int>temp(26,0);
            for(auto &ch:x)
                temp[ch-'a']++;
            for(int i=0;i<26;i++)
                freq[i]=max(freq[i],temp[i]);
        }
        
        vector<string>res;
        for(auto &x:words1)
        {
            vector<int>temp(26,0);
            for(auto &ch:x)
                temp[ch-'a']++;
            
            bool f=1;
            for(int i=0;i<26;i++)
            {
                if(temp[i]<freq[i])
                {
                    f=0;
                    break;
                }
            }
            if(f)
                res.push_back(x);
        }
        
        return res;
    }
};