class Solution {
    string calc(string s)
    {
        if(s=="")return "+";
        int add=0,sub=0;
        int i=0,res=0;
        if(s[0]!='-')s='+'+s;
        int n=s.length();
      
        while(i<n)
        {
            char sign;
                sign=s[i++];
                int num=0;
            
                while(i<n&&s[i]>='0'&&s[i]<='9')
                num=num*10+(s[i++]-'0');
            
                if(sign=='+')
                    add+=num;
                else
                    sub+=num;
        }
        res=add-sub;
        string x=to_string(abs(res));
        return res<0?'-'+x:'+'+x;
    }
public:
    int calculate(string s) 
    {
        vector<string>st;
        if(s[0]!='-')
            s='+'+s;
        int n=s.length();
        int res=0;
        string x="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')continue;
            if(s[i]=='(')
            {
                if(st.size()==0||st.back()=="(")
                st.push_back(x);
                else
                    st.back()+=x;
                st.push_back("(");
                x="";
            }
            else if(s[i]==')')
            {
                string r;
                if(st.back()=="(")
                {r=calc(x);
                 // cout<<r<<"\n";
                }
                else
                {r=calc(st.back()+x);
                 // cout<<r<<"\n";
                 st.pop_back();}
                st.pop_back();
                
                if(st.back().back()!=r[0])
                    st.back().back()='-';
                else
                    st.back().back()='+';
                
                st.back()+=(r.substr(1));
                x="";
            }
            else
            {
               x+=s[i]; 
            }
        }
        
        if(x.size()!=0)
            st.push_back(x);
        
        x="";
        for(auto &it:st)
        {x+=it;}
        
        string ans=calc(x);
        res=stoi(ans.substr(1));
        
        return ans[0]=='-'?-res:res;
    }
};


//"34-(4+(12-(3+12-33)-2+12-(18+2)+1)-20)"
//"45+(6-10+12-(45+1-(34)+12)-66)+12"