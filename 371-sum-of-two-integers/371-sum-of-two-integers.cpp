#define ll long long int
class Solution {
public:
    int getSum(int a, int b) 
    {
        ll aa=a;
        ll bb=b;
        ll res=0;
        int carry=0;
       
        int i=0;
        for(;i<32;i++)
        {
            int bita=aa&(1LL<<i)?1:0;
            int bitb=bb&(1LL<<i)?1:0;
            if((bita^bitb)^carry)
                res|=(1LL<<i);
            if(bita&bitb)carry=1;
            else if(bita|bitb)continue;
            else 
                carry=0;
        }
        if(carry)
            res|=(1LL<<i);

        return res;
    }
};
/*
1001
1011
-----
 100
*/
               
             
               
               