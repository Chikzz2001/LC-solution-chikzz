```
class Solution {
set<vector<int>>res1;
void helper(vector<int>& nums,int s,int e)
{
int n=(e-s+1);
for(int i=3;i<(1<<n);i++)
{
if(!(i&(i-1)))continue;
vector<int>temp;
for(int j=0;j<n;j++)
{
if(i&(1<<j))
temp.push_back(nums[s+j]);
}
res1.insert(temp);
}
}
public:
vector<vector<int>> findSubsequences(vector<int>& nums)
{
int i=0,j=0,n=nums.size();
while(j<n)
{
while(j+1<n&&nums[j]<=nums[j+1])
j++;
if(j>i)
helper(nums,i,j);
j++;
i=j;
}
vector<vector<int>>res;
for(auto &x:res1)res.push_back(x);
return res;
}
};
```