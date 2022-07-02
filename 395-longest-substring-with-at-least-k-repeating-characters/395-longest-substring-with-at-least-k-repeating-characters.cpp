class Solution {
    bool valid(vector<int>& freq,int &k)
    {
        for(int i=0;i<26;i++)
        {
            if(!freq[i]||freq[i]>=k)continue;
            return 0;
        }
        return 1;
    }
public:
    int longestSubstring(string s, int k) 
    {
        if(k>s.length())return 0;
        int i=0,j=0,res=0;
        int n=s.length();
        
        vector<int>freq(26,0);
        while(j<n)
        {
            freq[s[j]-'a']++;
            
            vector<int>tf=freq;
            while(j-i+1>=k&&!valid(tf,k))
            {
                tf[s[i++]-'a']--;
            }
          
            if(j-i+1>=k)
            res=max(res,j-i+1);
            i=0;
            j++;
        }
        return res;
    }
};