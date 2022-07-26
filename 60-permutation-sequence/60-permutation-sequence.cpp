class Solution {
    string helper(vector<int>& nums,int k,int p)
    {
        if(nums.size()==1)return to_string(nums[0]);
        
        int idx=k/p;
        
        int get=nums[idx];
        nums.erase(nums.begin()+idx);
        return to_string(get)+helper(nums,k%p,p/(nums.size()));
    }
public:
    string getPermutation(int n, int k) 
    {
        vector<int>nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        
        int p=1;
        for(int i=1;i<n;i++)p*=i;
        
        return helper(nums,k-1,p);
    }
};
