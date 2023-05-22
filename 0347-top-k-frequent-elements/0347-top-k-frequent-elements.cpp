class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int>res;
        //map<int,vector<int>,greater<int>>buckets;
        unordered_map<int,int>freq;
        
        for(auto &x:nums)
            freq[x]++;
                
//         for(auto [num,times]:freq)
//         {
//             buckets[times].push_back(num);
//         }
        
//         int counter=0;
//         for(auto &[bucket,num]:buckets)
//         {
//             int size=num.size();
//             int i=0;
//             while(counter<k&&i<size)
//             {
//                 res.push_back(num[i]);
//                 i++;
//                 counter++;
//             }
//         }
        
        priority_queue<pair<int,int>>pq;
        
        for(auto &[num,times]:freq)
        {
            pq.push({-times,num});
            if(pq.size()>k)
                pq.pop();
        }
        
        while(!pq.empty())
        {
            auto [negtimes,num]=pq.top();
            pq.pop();
            res.push_back(num);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};