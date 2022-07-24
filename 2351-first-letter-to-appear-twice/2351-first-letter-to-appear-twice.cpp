class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int>m;
        char res;
        for(auto &ch:s)
        {
            if(m.count(ch))return ch;
            m[ch]++;
        }
        return '#';
    }
};