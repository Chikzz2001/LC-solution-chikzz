class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res=1,sum=0;
        for(auto &x:nums)
        {
            sum+=x;
            if(sum<=0)
                res=max(res,-sum+1);
        }
        
        return res;
    }
};

/*

-3 -1 -4

*/