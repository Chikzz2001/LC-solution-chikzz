// #define ms_iter multiset<int>::iterator
class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
       unordered_map<int,multiset<int>>m;
        for(auto &x:nums)
        {
            if(!m.count(x-1))
            {
                m[x].insert(1);
            }
            else
            {
                auto it=m[x-1].begin();
                int freq=*it;
                m[x].insert(freq+1);
                m[x-1].erase(it);
                //cout<<x-1<<"\n";
                if(m[x-1].size()==0)m.erase(x-1);
            }
        }
        
        for(auto &[x,y]:m)
        {
            for(auto &z:y)
            { 
                //cout<<x<<" "<<z<<"\n";
                if(z<3)return 0;
            }
        }
        return 1;
    }
};

/*



*/

