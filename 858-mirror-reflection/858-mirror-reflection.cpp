class Solution {
public:
    int mirrorReflection(int p, int q) {
        /*
        
        a*p=b*q
        a*3=b*1
        
        
        */
        
        while (p%2==0&&q%2==0)
        { 
            p/=2;
            q/=2;
        }
        return ((p&1)&&(q&1))?1:(p&1)?0:2;
    }
};