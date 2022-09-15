class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        //sort the intervals on absis of start time
        //remove all intervals that do not coinside with the current interval and take max_val of 
        //their values
        //take max of current intervals value and the one that does not coincide with the current one
        
        sort(events.begin(),events.end());
        //end_time,{start_time,value}
        priority_queue<pair<int,pair<int,int>>>pq;
        int res=0,max_value=0;
        
        for(int i=0;i<events.size();i++)
        {
            while(!pq.empty()&&(-1*pq.top().first)<events[i][0])
            {
                max_value=max(max_value,pq.top().second.second);
                pq.pop();
            }
            res=max(res,events[i][2]+max_value);
            pq.push({-events[i][1],{events[i][0],events[i][2]}});
        }
        return res;
    }
};

//{s1,e1},{s2,e2},{s3,e3}.......
//e1,e2-->ascending order