class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(int x:arr)m[x]++;
        set<int>s;
        for(auto [x,y]:m)s.insert(y);
        return m.size()==s.size();
    }
};