class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string s[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string>ss;
        for(string x:words)
        {string str="";
            for(char ch:x)
            {
                str+=s[ch-'a'];
            }
         ss.insert(str);
        }
        return ss.size();
        
    }
};