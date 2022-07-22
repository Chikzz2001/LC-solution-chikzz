class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       
        int n=nums.size();
        if (n<3)return 0;

        int res=0;
        vector<int>v;
        for(int i=1;i<n;i++)
        {
            v.push_back(nums[i]-nums[i-1]);
        }
        
        for(int i=0;i<n-2;)
        {
            if(v[i]==v[i+1])
            {
                int x=v[i];
                int count=0;
                while(i<n-1&&v[i]==x)
                {
                    i++;
                    count++;
                }
                res+=(count*(count-1))/2;
            }
            else
                i++;
        }
        return res;
        
        //1 1 1 1
        //1 2 3 4
        
        //2 3 4 1 3 5 7 9 18 27
        //  1 1 -3 2 2 2 2 9 9
        //0 1 2-2 0 2 4 6 15 24
    }
};