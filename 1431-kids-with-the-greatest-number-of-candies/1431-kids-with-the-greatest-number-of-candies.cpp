class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxx=*max_element(candies.begin(),candies.end());
        vector<bool>res;
        for(int x:candies) {
            if(x+extraCandies>=maxx)res.push_back(1);
            else res.push_back(0);
        }
        return res;
    }
};