class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int>r;
        int i=nums.size()-1;
        int c=0;
        while(k) {
            int s=(i>=0?nums[i]:0)+k%10+c;
            c=s/10;
            r.push_back(s%10);
            k/=10;
            i--;
        }
        while(i>=0) {
            int s=nums[i]+c;
            c=s/10;
            r.push_back(s%10);
            i--;
        }
        if(c)r.push_back(c);
        reverse(r.begin(),r.end());
        return r;
    }
};