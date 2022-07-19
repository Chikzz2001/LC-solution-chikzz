class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        set<int>S;
        int res=0;
        if(!k)
        {
            map<int,int>m;
            for(auto &n:nums)m[n]++;
            for(auto &[x,y]:m)
                res=y>1?res+1:res;
            return res;
        }
        
        //x-target=k-->target=x-k
        //target-x=k-->target=x+k
        S.insert(nums.begin(),nums.end());
        
        for(auto &x:S)
        {
            if(S.count(x+k))
                res++;
            if(S.count(x-k)&&k!=0)
                res++;
            S.erase(x);
        }
        return res;
    }
};