class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>v(26,0);
        for(int i=0;i<sentence.length();i++)
        {
            v[sentence[i]-'a']++;
        }
        bool f=1;
        for(auto x:v)
        {
            if(x==0)
            {
                f=0;
                break;
            }
        }
        return f;
    }
};