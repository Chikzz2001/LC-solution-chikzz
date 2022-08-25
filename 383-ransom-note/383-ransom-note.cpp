class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26]={0},b[26]={0};
        for(char x:ransomNote)
            a[x-'a']++;
        
        for(char x:magazine)
            b[x-'a']++;
        
        for(int i=0;i<26;i++)
        {
            if(a[i]>b[i])return 0;
        }
        return 1;
    }
};