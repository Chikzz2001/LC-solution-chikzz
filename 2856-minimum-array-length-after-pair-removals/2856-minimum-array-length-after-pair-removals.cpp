class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(int i=n/2;i<n;i++)m[nums[i]]++;
       
        int res=0;
        for(int i=0;i<n/2;i++) {
            auto it=m.upper_bound(nums[i]);
            if(it==m.end())res++;
            else {
                it->second--;
                if(it->second==0)m.erase(it);
            }
        }
        
        for(auto [x,y]:m)res+=y;
        return res;
    }
};