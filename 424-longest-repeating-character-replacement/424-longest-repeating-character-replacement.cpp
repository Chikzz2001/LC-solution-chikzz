class Solution {
    bool check(vector<int>& freq,int k)
    {
        int maxfreq=0,sum=0;
        for(int i=0;i<26;i++)
        {
            sum+=freq[i];
            maxfreq=max(maxfreq,freq[i]);
        }
        return sum-maxfreq<=k;
    }
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0,j=0,res=0;
        
        vector<int>freq(26,0);
        while(j<n)
        {
            freq[s[j]-'A']++;
            
            while(i<j&&!check(freq,k))
            {
                freq[s[i]-'A']--;
                i++;
            }
            
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};