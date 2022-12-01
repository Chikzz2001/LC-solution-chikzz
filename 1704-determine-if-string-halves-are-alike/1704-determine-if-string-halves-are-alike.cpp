class Solution {
    bool vowel(char x){return x=='a'||x=='e'||x=='o'||x=='i'||x=='u';}
public:
    bool halvesAreAlike(string s) {
        int c1=0,c2=0;
        for(int i=0;i<s.length()/2;i++)
        {
            s[i]=s[i]>='A'&&s[i]<='Z'?s[i]-'A'+'a':s[i];
            if(vowel(s[i]))c1++;
        }
        for(int i=s.length()/2;i<s.length();i++)
        {
            s[i]=s[i]>='A'&&s[i]<='Z'?s[i]-'A'+'a':s[i];
            if(vowel(s[i]))c2++;
        }
        
        return c1==c2;
    }
};