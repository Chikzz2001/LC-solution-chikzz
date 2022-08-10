class Solution {
    int maxsublen_of_first_in_second(vector<int>& nums1,vector<int>& nums2)
    {
        int n=nums1.size(),m=nums2.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;)
            {
                if(nums1[i]==nums2[j])
                {
                    int k=i;
                    int len=0;
                    while(j<m&&k<n&&nums1[k]==nums2[j])
                        j++,k++,len++;
                    if(len>res)
                    {
                        res=max(res,len);
                    }
                    
                }
                else
                    j++;
            }
        }
        return res;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return max(maxsublen_of_first_in_second(nums1,nums2),maxsublen_of_first_in_second(nums2,nums1));
    }
};

/*

[0,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,1,0,0,0,1]
[1,0,1,1,0,1,1,1,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0]

*/