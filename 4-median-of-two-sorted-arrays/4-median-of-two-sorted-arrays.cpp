class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size()<nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int n=nums1.size(),m=nums2.size();
        
        int lo=0,hi=min(m,(n+m+1)/2);
        
        while(lo<=hi)
        {
            int cut2=lo+(hi-lo)/2;
            int cut1=(n+m+1)/2-cut2;
            
            int l2=cut2==0?INT_MIN:nums2[cut2-1];
            int l1=cut1==0?INT_MIN:nums1[cut1-1];
            
            int r2=cut2==m?INT_MAX:nums2[cut2];
            int r1=cut1==n?INT_MAX:nums1[cut1];
            
            if(l1<=r2&&l2<=r1)
            {
                if((m+n)&1)
                    return max(l1,l2);
                else
                {
                    double res=0;
                    res+=max(l1,l2);
                    res+=min(r1,r2);
                    return res/2.0;
                }
            }
            else if(l2>r1)
            {
                hi=cut2-1;
            }
            else
            {
                lo=cut2+1;
            }
        }
        return 0;
    }
};