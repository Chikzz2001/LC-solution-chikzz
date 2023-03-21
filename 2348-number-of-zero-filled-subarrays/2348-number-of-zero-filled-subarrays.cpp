class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      long long res=0;
        for(int i=0;i<nums.size();) {
            if(nums[i]==0) {
                int c=0;
                while(i<nums.size()&&nums[i]==0) {
                    c++;i++;
                }
                res+=(1ll*c*(c+1))/2;
            }
            else i++;
        }
        return res;
    }
};