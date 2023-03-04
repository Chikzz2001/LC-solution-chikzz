#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        ll res=0;
        ll lbad=-1,jmi=-1,jma=-1;
        for (int i=0;i<n;i++) {
            if(nums[i]<minK||nums[i]>maxK)lbad=i;
            if(nums[i]==minK)jmi=i;
            if(nums[i]==maxK)jma=i;
            res+=max(0ll,min(jmi,jma)-lbad);
        }
        return res;
    }
};

/*

    1 3 5 2 7 5
    0 1 2 3 4
    5-->
    
    -1,6 
    
    x---------i ----- j---------y
    (i-x)+(y-j)
*/