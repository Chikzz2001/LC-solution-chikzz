class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int sum=0;
        for(auto &x:nums)
        {
            if(x%2==0)sum+=x;
        }
        
        vector<int>res;
        for(auto &q:queries)
        {
            //odd odd
            if(nums[q[1]]&1&&abs(q[0])&1)
            {
                nums[q[1]]+=q[0];
                sum+=(nums[q[1]]);
            }
            //even even
            else if(nums[q[1]]%2==0&&abs(q[0])%2==0)
            {
                nums[q[1]]+=q[0];
                sum+=q[0];
            }
            //even odd
            else if(nums[q[1]]%2==0&&abs(q[0])&1)
            {
                sum-=nums[q[1]];
                nums[q[1]]+=q[0];
            }
            //odd even
            else if(nums[q[1]]&1&&abs(q[0])%2==0)
            {
                nums[q[1]]+=q[0];
            }
            res.push_back(sum);
        }
        return res;
    }
};