class Solution {
public:
    string toHex(int num) 
    {
        if(num==0)return "0";
        string res;
        long long n;
        if(num<0)
            n=4294967296+num;
        else 
            n=num;
        
        while(n)
        {
            int a=n%16;
            if(a>9)
                res+='a'+a-10;
            else
                res+='0'+a;
            n/=16;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};