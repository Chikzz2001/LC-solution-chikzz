class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.length()==0)return 0;
        unordered_map<char,int>m;
        int i=0,j=0,res=1;
        
        int n=s.length();
        while(j<n)
        {
            m[s[j]]++;
            
            while(i<j&&(j-i+1)!=m.size())
            {
                m[s[i]]--;
                if(m[s[i]]==0)m.erase(s[i]);
                i++;
            }
            
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};