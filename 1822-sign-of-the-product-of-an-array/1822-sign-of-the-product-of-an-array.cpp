class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=0,p=0;bool f=1;
        for(int x:nums)
        {
            if(x==0){f=0;break;}
                else
                {
                    if(x<0)n++;
                    else
                        p++;
                }
        }
        if(!f)return 0;
        else
        {
            if(n&1)return -1;
            return 1;
        }
    }
};