class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        string s=needle+"#"+haystack;
        
        int nn=needle.length();
        int n=s.length();
        int lps[n];
        
        lps[0]=0;
        int len=0;
        
        for(int i=1;i<n;)
        {
            if(s[i]==s[len])
            {
                lps[i]=++len;
                if(len==nn)
                {return i-(nn-1)-(nn+1);}
                i++;
            }
            else
            {
                if(len>0)
                    len=lps[len-1];
                else
                {
                    lps[i++]=0;
                }
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<lps[i]<<" ";
        return -1;
    }
};

//ll#hello
//0100012
//0123456