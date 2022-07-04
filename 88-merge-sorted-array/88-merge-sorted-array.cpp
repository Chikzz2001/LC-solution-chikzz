class Solution {
    void sortNums2(vector<int>& nums2,int start,int m)
{
int j=start+1;
while(j<m&&nums2[j-1]>nums2[j])
{
swap(nums2[j],nums2[j-1]);
j++;
}
}

public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) 
    {
       if(nums1.size()<nums2.size())
{
merge(nums2,m,nums1,n);return;
}
int i=0,j=0;
while(i<n&&j<m)
{
if(nums1[i]>nums2[j])
{
swap(nums1[i],nums2[j]);
sortNums2(nums2,j,m);
}
i++;
}
for(int i=n;i<n+m;i++)
    nums1[i]=nums2[i-n];
    }
};