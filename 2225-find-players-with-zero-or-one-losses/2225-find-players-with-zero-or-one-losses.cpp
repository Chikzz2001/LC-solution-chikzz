class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>win,lose;
        for(auto &x:matches)
            win[x[0]]++,lose[x[1]]++;
        vector<vector<int>>res(2);
        for(auto &[x,y]:win)
            if(!lose.count(x))res[0].push_back(x);
    
        for(auto &[x,y]:lose)
            if(y==1)res[1].push_back(x);
        
        sort(res[0].begin(),res[0].end());
        sort(res[1].begin(),res[1].end());
        return res;
        
    }
};