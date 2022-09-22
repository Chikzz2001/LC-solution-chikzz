class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string w;
        string res;
        while(ss>>w)
        {
            string x=w;
            reverse(x.begin(),x.end());
            res+=x+" ";
        }
        res.pop_back();
        return res;
    }
};