class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,j=0,n=chars.size();
        for(int i=0;i<n;) {
            int c=0;
            char ch=chars[i];
            while(i<n&&chars[i]==ch) {
                c++;i++;
            }
            chars[j++]=ch;
            if(c>1) {
                string s=to_string(c);
                for(int k=0;k<s.length();k++,j++)chars[j]=s[k];
            }
        }
        while(n>j) {
            chars.pop_back();
            n--;
        }
        return j;
    }
};