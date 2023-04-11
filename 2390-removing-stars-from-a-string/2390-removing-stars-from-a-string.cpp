class Solution {
public:
    string removeStars(string s) {
        vector<int>v;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='*') {
                s[v.back()]='#';
                s[i]='#';
                v.pop_back();
            }
            else v.push_back(i);
        }
        string res;
        for(char ch:s) {
            if(ch=='#')continue;
            res+=ch;
        }
        return res;
    }
};