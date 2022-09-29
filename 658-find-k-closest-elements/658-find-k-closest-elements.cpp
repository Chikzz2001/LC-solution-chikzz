class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto &y:arr)
        {
            pq.push({abs(y-x),(y-x)});
        }
        
        // while(!pq.empty())
        // {
        //     cout<<pq.top().first<<" "<<pq.top().second<<"\n";
        //     pq.pop();
        // }
        // return {};
        vector<int>res;
        
        while(k--)
        {
            auto [diff,sign]=pq.top();
            pq.pop();
            
                if(sign<0)
                    res.push_back(x-diff);
                else
                    res.push_back(x+diff);
            
            }

        sort(res.begin(),res.end());
        
        return res;
    }
};