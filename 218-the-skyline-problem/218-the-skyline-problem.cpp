class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int,int>>coordinates;
        
        for(auto &b:buildings)
        {
            coordinates.push_back({b[0],-b[2]});
            coordinates.push_back({b[1],b[2]});
        }
        
        sort(coordinates.begin(),coordinates.end());
        
        multiset<int,greater<int>>S;
        
        int current_height=0;
        S.insert(0);
        
        vector<vector<int>>res;
        
        for(auto &[x,y]:coordinates)
        {
            if(y<0)
            {
                S.insert(-y);
            }
            else
            {
                auto it=S.find(y);
                S.erase(it);
            }
            
            if(current_height!=*(S.begin()))
            {
                res.push_back({x,*(S.begin())});
                current_height=*(S.begin());
            }
        }
        
        return res;
    }
};