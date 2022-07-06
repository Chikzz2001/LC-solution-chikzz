class Solution {
public:
    int fib(int n) 
    {
        if(n<2)return n;
        if(n==2)return 1;
        int a=1,b=1,t;
        n-=2;
        while(n--)
        {
            t=a+b;
            a=b;
            b=t;
        }
        return t;
    }
};