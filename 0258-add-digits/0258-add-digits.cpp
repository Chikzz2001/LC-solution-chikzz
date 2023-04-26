class Solution {
public:
    int addDigits(int num) {
        while(num>=10)
        {
            int sum=0;
            int t=num;
            while(t)
            {
                sum+=t%10;
                t/=10;
            }
            num=sum;
        }
        return num;
    }
};