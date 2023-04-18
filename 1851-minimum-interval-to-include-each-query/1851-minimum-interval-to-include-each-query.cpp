class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //line sweep
        map<int,set<pair<int,int>>>line;
        
        //entry:0 exit:1 query:2
        
        for(auto i:intervals) {
            line[i[0]].insert({0,i[1]-i[0]+1});
            line[i[1]+1].insert({1,i[1]-i[0]+1});
        }
        
        for(int i=0;i<queries.size();i++) {
            line[queries[i]].insert({2,i});
        }
        multiset<int>available_size;
        
        vector<int>res(queries.size());
        for(auto &[point,args]:line) {
            for(auto &[type,x]:args) {
                if(type==0) {
                    available_size.insert(x);
                }
                else if(type==1) {
                    auto it=available_size.lower_bound(x);
                    available_size.erase(it);
                }
                else {
                    int val=*(available_size.begin());
                    res[x]=val?val:-1;
                }
            }
        }
        return res;
    }
};