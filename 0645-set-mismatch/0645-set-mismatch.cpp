class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int XOR=0,n=nums.size();
        for(int i=1;i<=n;i++)XOR^=i;
        for(auto &x:nums)XOR^=x;
        
        int LSB;
        for(int i=0;i<32;i++)
        {
            if(XOR&(1<<i))
            {
                LSB=i;
                break;
            }
        }
        
        int XOR1=0,XOR2=0;
        for(auto &x:nums)
        {
            if(x&(1<<LSB))XOR1^=x;
            else
                XOR2^=x;
        }
        for(int i=1;i<=n;i++)
        {
            if(i&(1<<LSB))XOR1^=i;
            else
                XOR2^=i;
        }
        
        for(auto &x:nums)
        {
            if(x==XOR1)return {XOR1,XOR2};
        }
        return {XOR2,XOR1};
    }
};