class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=0,r=*max_element(nums.begin(),nums.end());
        
        while((r-l)>1) {
            int m=l+(r-l)/2;
            
            bool ok=1;
            int k=maxOperations;
            for(int i=0;i<nums.size();i++) {
                if(nums[i]<=m)continue;
                if(((nums[i]+m-1)/m-1)<=k) {
                    k-=((nums[i]+m-1)/m-1);
                    }
                    else {
                        ok=0;
                        break;
                    }
                }
            
            if(ok)r=m;
            else l=m;
            }
        return r;
    }
};