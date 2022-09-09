class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
//LIS--->nlogk where n is the size of the array from which LIS is found and k is the size of the LIS array.
      vector<int>LIS;
        
        for(auto &x:nums)
        {
           if(LIS.size()==3)return 1;
            if(LIS.empty()||LIS.back()<x)
                LIS.push_back(x);
            else
            {
                int idx=lower_bound(LIS.begin(),LIS.end(),x)-LIS.begin();
                LIS[idx]=x;
            }
        }
        if(LIS.size()>=3)return 1;
        return 0; 
    }
};