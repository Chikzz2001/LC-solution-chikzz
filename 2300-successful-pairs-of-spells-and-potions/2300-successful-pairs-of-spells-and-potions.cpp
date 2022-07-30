class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(),potions.end());
        
        vector<int>res;
        
        int n=potions.size();
        
        for(auto &s:spells)
        {
            long long find=success%s?success/s+1:success/s;
            int idx=lower_bound(potions.begin(),potions.end(),find)-potions.begin();
            res.push_back(n-idx);
        }
        
        return res;
    }
};