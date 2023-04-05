class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l=-1,r=-1;
        for(int i=0;i<nums.size();i++)r=max(r,nums[i]);
        while((r-l)>1) {
            int m=l+r>>1;
            bool ok=1;
            long long tot=0;
            for(int i=0;i<nums.size();i++) {
                if(nums[i]-tot>m){ok=0;break;}
                tot-=max(0,nums[i]-m);
                tot+=max(0,m-nums[i]);
            }
            if(ok)r=m;
            else l=m;
        }
        return r;
    }
};