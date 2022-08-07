class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>help(n);
        int i=n&1?n/2:n/2-1,j=n-1,c=0;
        while(c<n)
        {
            if(c&1)
            {
                help[c]=nums[j];
                j--;
            }
            else
            {
                help[c]=nums[i];
                i--;
            }
            c++;
        }
        nums=help;
    }
};


/*

1,1,1,4,5,6
1,

*/