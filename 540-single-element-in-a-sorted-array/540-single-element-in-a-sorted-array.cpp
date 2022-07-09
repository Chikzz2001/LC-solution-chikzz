class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
if(n==1)return nums[0];

int low=0;
int high=n-1;

while(low<high){
  int mid=(low+high)>>1;

  if(mid&1){
       if(nums[mid-1]==nums[mid]){
         low=mid+1;
       }
       else{
          high=mid;
       }
  }
 else{

       if(nums[mid]==nums[mid+1]){
            low=mid+1;
       }
      else{
      high=mid;
      }
 
  }
}

return nums[high];

        }
};

//3 7 7 10 10 11 11
//0 1 2 3 4  5  6--->n=7