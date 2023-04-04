class Solution {
public:
    int partitionString(string s) {
        int part=1;
        unordered_set<char>S;
        for(auto &x:s)
        {
            if(S.count(x))
            {
                part++;
                S.clear();
                S.insert(x);
            }
            else
            {
                S.insert(x);
            }
        }
        return part;
    }
};