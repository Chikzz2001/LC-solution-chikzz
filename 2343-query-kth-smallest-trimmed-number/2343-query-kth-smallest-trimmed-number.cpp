class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        int n=nums[0].length();
        vector<int>res;
        for(auto &q:queries)
        { 
            int i=0;
            priority_queue<pair<string,int>>pq;
            for(auto &x:nums)
            {
                string s=x.substr(n-q[1]);
                pq.push({s,i});
                if(pq.size()>q[0])
                    pq.pop();
                i++;
            }
            res.push_back(pq.top().second);
        }
        return res;
    }
};