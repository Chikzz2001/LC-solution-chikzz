class Solution {
public:
    string makeFancyString(string s) 
    {
        string res;
        int n=s.length();
        for(int i=0;i<n;)
        {
            char ch=s[i];
            int j=i;
            while(i<n&&s[i]==ch)
                i++;
            if(i-j>=2)
            {
                res+=ch;
                res+=ch;
            }
            else
                res+=ch;
        }
        return res;
    }
};