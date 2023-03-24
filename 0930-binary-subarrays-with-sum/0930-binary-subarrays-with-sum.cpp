class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int>pre;
        int s=0,res=0;
        for(int i=0;i<nums.size();i++) {
            s+=nums[i];
            pre.push_back(s);
            int id1=upper_bound(pre.begin(),pre.end(),s-goal)-pre.begin();
            int id2=lower_bound(pre.begin(),pre.end(),s-goal)-pre.begin();
            id1=min(id1,(int)pre.size()-1);
            if(pre[id2]>s-goal)id2--;
            if(s>=goal)res+=id1-(s-goal==0?-1:id2);
        }
        return res;
    }
};

/*
0 1 2 3 4
*/