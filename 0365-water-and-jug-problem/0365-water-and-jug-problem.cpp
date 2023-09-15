class Solution {
public:
    bool canMeasureWater(int j1, int j2, int C) {
        if(C>(j1+j2))return 0;
        return (C%gcd(j1,j2)==0);
    }
};