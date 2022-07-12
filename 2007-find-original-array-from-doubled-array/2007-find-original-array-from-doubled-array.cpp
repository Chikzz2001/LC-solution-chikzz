class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        if(changed.size()&1)return {};
        unordered_map<int,int>freq;
        for(auto &x:changed)
            freq[x]++;
        
        sort(changed.begin(),changed.end());
        
        vector<int>res;
        for(auto &x:changed)
        {
            if(!freq[x])continue;
            freq[x]--;
            if(!freq[2*x])
            return {};
            freq[2*x]--;
            res.push_back(x);
        }
        return res;
    }
};

/*

1 2 3 4 6 8

1 1 2 4

*/