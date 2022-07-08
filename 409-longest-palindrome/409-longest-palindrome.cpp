class Solution {
public:
    int longestPalindrome(string s) 
    {
        int odd=0;
        map<char,int>m;
        for(auto &x:s)
            m[x]++;
        int res=0;
        for(auto &[x,y]:m)
        {
            if(y&1)odd=1;
            res+=(y/2)*2;
        }
        return res+odd;
    }
};