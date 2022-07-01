class Solution {
public:
    string toHex(int num) 
    {
        if(num==0)return "0";
        string res;
        unsigned int n=num;
        
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