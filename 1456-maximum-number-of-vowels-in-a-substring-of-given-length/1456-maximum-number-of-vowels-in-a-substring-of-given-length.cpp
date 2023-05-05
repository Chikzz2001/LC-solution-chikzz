class Solution {
    bool isvowel(char ch) {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
public:
    int maxVowels(string s, int k) {
        int count=0,res=0;
        for(int i=0;i<k;i++) {
            if(isvowel(s[i]))count++;
        }
        for(int i=0;i<=s.length()-k;i++) {
            if(i) {
                if(isvowel(s[i+k-1]))count++;
                if(isvowel(s[i-1]))count--;
            }
            res=max(res,count);
        }
        return res;
    }
};