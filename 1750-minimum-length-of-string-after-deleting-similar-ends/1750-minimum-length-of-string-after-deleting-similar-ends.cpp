class Solution {
public:
    int minimumLength(string s) 
    {
        int n=s.length();
        if(n==1)return 1;
        int i=0,j=n-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return (j-i+1);
            char x=s[i];
            while(i<j&&s[i]==x)
                i++;
            if(i==j)return 0;
            while(i<j&&s[j]==x)
                j--;
            if(i==j)return 1;
        }
        return 0;
    }
};

