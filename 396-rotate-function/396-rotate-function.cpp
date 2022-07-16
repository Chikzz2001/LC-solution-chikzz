class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int sum=0;
        int temp=0,i=0;
        for(auto &x:nums)
        {
            sum+=x;
            temp+=(i++)*x;
        }
        int maxx=temp;
        for(int i=nums.size()-1;i>=0;i--)
        {
            //cout<<temp<<"\n";
            temp=temp-nums.size()*nums[i]+sum;
            maxx=max(maxx,temp);
        }
        return maxx;
    }
};

/*

4 3 2 6-->25-18+4+3+2

---->16-6+4+3+6=

*/