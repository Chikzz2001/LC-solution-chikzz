class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        string s="11";
        
        for(int i=3;i<=n;i++)
        {
          int c=1,l=s.length();
            string ans="";
            for(int j=1;j<l;j++)
            {
                if(s[j]!=s[j-1])
                {
                   ans+=to_string(c);
                    ans+=s[j-1];
                    c=1;
                }
                else
                    c++;
            }
            if(l>=2){
            if(s[l-1]==s[l-2])
            {
                ans+=to_string(c);
                    ans+=s[l-1]; 
            }
                else
                {
                   ans+="1";
                    ans+=s[l-1];
                }
                }
            s=ans;
        }
        return s;
    }
};