class Solution {
public:
    bool isPowerOfThree(int n) 
    {
       if(n<=1) 
           return n==1;
	return isPowerOfThree(n/3)&(n%3==0);
    }
};

