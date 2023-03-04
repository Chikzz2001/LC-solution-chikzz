class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int r=0,n=nums.size();
        // for(int x:nums)cout<<x<<" ";
        int i=n/2,j=0;
        while(j<n/2) {
            while(i<n&&2*nums[j]>nums[i])i++;
            if(i<n){r+=2;i++;}
            j++;
        }
        return r;
    }
};

/*
[9,2,5,4]
2 4 5 9

2 3 4 5

x y z   a b c
2*x>a-->2*b>a and 2*c>a
*/