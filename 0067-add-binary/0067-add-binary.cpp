class Solution {
public:
    string addBinary(string a, string b) {
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        string c="";
        int carry=0;
        int lena=a.length(),lenb=b.length();
        
        if(lena<lenb){swap(a,b);swap(lena,lenb);}
        
        b.append(lena-lenb,'0');
    
        for(int i=0;i<lena;i++)
        {
            char ch,sum=0;
                sum+=(a[i]-'0');
                sum+=(b[i]-'0');
                sum+=carry;
                carry=sum/2;
                ch=sum%2+'0';
            c+=ch;
        }
        
        if(carry)
            c+="1";
       
        reverse(c.begin(),c.end());
        return c;
    }
};