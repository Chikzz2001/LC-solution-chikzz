class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(char x:s)
            mp[x]++;
           
           for(char x:t) {
                mp[x]--;
            if(mp[x]==0)mp.erase(x);
        }
        return (mp.size()==0);
    }
};