```
class Solution {
public:
int minStartValue(vector<int>& nums) {
int sum=0,int res=0,n=nums.size();
for(int i=0;i<n;i++)
{
sum+=nums[i];
if(sum<1)
{
if(i+1<n)
{
if(nums[res]>nums[i+1]&&nums[i+1]>0)
{
res=i+1;
}
}
}
sum=0;
}
sum=0;
for(int i=res;i<n;i++)
{
sum+=nums[i];
if(sum<1)return -1;
}
return res;
}
};
```