class Solution {
public:
    bool isUgly(int N) {
        if(N<=0)return 0;
   
        while(N>1&&N%5==0){N/=5;}
        while(N>1&&N%3==0){N/=3;}
        while(N>1&&N%2==0){N/=2;}
       
        return N==1; 
    }
};