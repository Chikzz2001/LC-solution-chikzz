class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)return 0;
        if((1<<(int)log2(n))==n&&((int)log2(n))%2==0)return 1;
        return 0;
    }
};