class Solution {
public:
    int minOperations(int n) {
        string s="0";
        while(n) {
            if(n&1)s+='1';
            else s+='0';
            n>>=1;
        }
        // s+="0";
        // string ss="0";s+=ss;
        int res=0;
        reverse(s.begin(),s.end());
        // cout<<s;
        if(s.length()>=4) {
            if(s.substr(0,4)=="1010") {
                s[0]='0';
                s[2]='0';
                res+=2;
            }
        }
        
        for(int j=0;j+4<s.length();j++) {
            if(s.substr(j,5)=="01010") {
                s[j+1]='0';
                s[j+3]='0';
                res+=2;
            }
        }
        
        // cout<<s<<"\n";
        bool f=0;
        vector<int>st;
        for(int i=0;i<s.length();) {
            if(s[i]=='1') {
                int c=0;
                while(i<s.length()&&s[i]=='1') {
                    i++;
                    c++;
                }
                if(f)
                st.back()+=c,res++;
                else st.push_back(c);
            }
            else {
                int c=0;
                while(i<s.length()&&s[i]=='0') {
                    i++;
                    c++;
                }
                if(c==1)f=1;
                //if(c==1&&i!=s.length()&&st.size())res++;
                else f=0;
            }
        }
        
        // for(int x:st)cout<<x<<" ";
        for(int x:st)res=res+(x==1?1:2);
        return res;
    }
};

/*
100111
110110

1111010110110
012345678
1+2+3

10
11
12
13
14
15
16
17
18
19
20
3
*/