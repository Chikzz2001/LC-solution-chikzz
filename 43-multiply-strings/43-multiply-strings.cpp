class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int len1=num1.length(),len2=num2.length();
        string res(len1+len2,'0');
        
        int offset=len1+len2-1,carry=0;
        for(int i=len1-1;i>=0;i--)
        {
            int k=offset--;
            for(int j=len2-1;j>=0;j--)
            {
                int sum=(res[k]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry;
                res[k]='0'+sum%10;
                carry=sum/10;
                k--;
            }
            if(carry)
            {
                int sum=res[k]-'0'+carry;
                res[k]='0'+sum%10;
                carry=sum/10;
            }
        }
        
        int i=0;
        while(i<res.length()&&res[i]=='0')i++;
        
        return res.substr(i)==""?"0":res.substr(i);
    }
};