class Solution {
public:
    int firstUniqChar(string s) {
        // unordered_map<char,int>mp;
        int a[26]={0};
        for(char x:s)
        a[x-'a']++;
        
        for(int i=0;i<s.length();i++)
        {
            if(a[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};