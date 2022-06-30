class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
       unordered_map<int,priority_queue<int>>m;
        for(auto &x:nums)
        {
            if(!m.count(x-1))
            {
                m[x].push(-1);
            }
            else
            {
                int freq=m[x-1].top();
                m[x].push(freq-1);
                m[x-1].pop();
                if(m[x-1].size()==0)m.erase(x-1);
            }
        }
        
        for(auto &[x,y]:m)
        {
            while(y.size())
            {
                if(-y.top()<3)
                    return 0;
                y.pop();
            }
        }
        return 1;
    }
};


