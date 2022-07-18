class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        priority_queue<pair<int,char>>freq;
        priority_queue<pair<int,int>>next_task;
        
        map<char,int>m;
        for(auto &t:tasks)
            m[t]++;
        
        for(auto &[x,y]:m)
            freq.push({y,x});
        
        int time=0;
        while(freq.size()||next_task.size())
        {
            while(next_task.size()&&-next_task.top().first<=time)
            {
                auto [t,task]=next_task.top();
                freq.push({m[task],task});
                next_task.pop();
            }
            
            if(freq.size())
            {
                auto [f,task]=freq.top();
                freq.pop();
                m[task]--;
                if(m[task])
                    next_task.push({-(time+n+1),task});
            }
            
            time++;
        }
        return time;
    }
};