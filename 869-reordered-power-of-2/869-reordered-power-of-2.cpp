class Solution {
    long sumOfDigits(int n) 
    {
        long res=0;
        while(n)
        {
            res+=pow(10,n%10);
            n/=10;
        }
        return res;
    }
public:
    bool reorderedPowerOf2(int n) 
    {
        //pow(2,c)=n
        //c=sqrt(n)
        
        //256=13 512=8 1024=7 2048=14
        
           long sd=sumOfDigits(n);
        for (int i=0;i<32;i++)
            if (sumOfDigits(1<<i)==sd)
                return 1;
        return 0;
    }
};


//256
//6+