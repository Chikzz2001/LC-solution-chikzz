class Solution {
public:
    int rangeBitwiseAnd(int l, int r) 
    {
        if(r==0||l==0)return 0;
        if(l==r)return l;
        double last=floor(log2(l));
        
        int res=0;
        for(int i=last;i>=0;i--)
        {
            if((l&(1<<i))&&(r&(1<<i))&&(r-l)<=(1<<i))
            {
                res|=(1<<i);
            }
        }
        return res;
    }
};


//10: 1010
//11: 1011