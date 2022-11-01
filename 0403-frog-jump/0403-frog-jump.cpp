class Solution {
    set<int>S;
    map<pair<int,int>,bool>dp;
    bool isPossible(int curr,int target,int jump)
    {
        if(curr==target)return 1;
        if(curr>target||!S.count(curr)||!jump)return 0;
        
        if(dp.count({curr,jump}))return dp[{curr,jump}];
        
        return dp[{curr,jump}]=isPossible(curr+jump+1,target,jump+1)|isPossible(curr+jump-1,target,jump-1)|isPossible(curr+jump,target,jump);
    }
public:
    bool canCross(vector<int>& stones) 
    {
        for(auto &x:stones)S.insert(x);
        
        if(stones[1]!=1)return 0;
        return isPossible(1,stones.back(),1);
    }
};