class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int n=s.length();
        
        int prev_ends_with_zero,prev_ends_with_one;
        prev_ends_with_zero=(s[0]=='0')?0:1,prev_ends_with_one=(s[0]=='1')?0:1;
        
        for(int i=1;i<n;i++)
        {
            int curr_ends_with_zero,curr_ends_with_one;
            if(s[i]=='0')
            {
                curr_ends_with_zero=prev_ends_with_zero;
                curr_ends_with_one=1+min(prev_ends_with_zero,prev_ends_with_one);
            }
            else
            {
                curr_ends_with_zero=1+prev_ends_with_zero;
                curr_ends_with_one=min(prev_ends_with_one,prev_ends_with_zero);
            }
            prev_ends_with_zero=curr_ends_with_zero;
            prev_ends_with_one=curr_ends_with_one;
        }
        
        return min(prev_ends_with_zero,prev_ends_with_one);
    }
};