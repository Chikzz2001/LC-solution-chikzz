class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) 
    {
        for(int i=n;i<n+m;i++)
        nums1[i]=nums2[i-n];

        int gap=(n+m)&1?(n+m+1)/2:(n+m)/2;
        while(1)
        {
            int i=0,j=gap;
            while(j<n+m)
            {
                if(nums1[i]>nums1[j])
                swap(nums1[i],nums1[j]);
                i++;j++;
            }
            if(gap==1)break;
            gap=gap&1?(gap+1)/2:gap/2;
        }
    }
};
