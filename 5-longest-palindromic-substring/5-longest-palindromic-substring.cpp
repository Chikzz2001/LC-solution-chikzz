class Solution {
    int expandAroundCenter(string &s,int l,int r)
    {
        while(l>=0&&r<s.length()&&s[l]==s[r])
            l--,r++;
        return r-l-1;
    }
public:
    string longestPalindrome(string s) 
    {
        if(s.length()<2)return s;
        int l=0,r=0;
        
        for(int i=0;i<s.length();i++)
        {
            int len1=expandAroundCenter(s,i,i);
            int len2=expandAroundCenter(s,i,i+1);
            int len=max(len1,len2);
            if(len>(r-l+1))
            {
                l=i-(len-1)/2;
                r=i+len/2;
            }
        }
        return s.substr(l,r-l+1);
    }
};

/*

babad

*/