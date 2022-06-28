class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int>freq(26,0);
        // int maxx=0;
        for(auto &ch:s)
        {
            freq[ch-'a']++;
            //maxx=max(freq[ch-'a'],maxx);
        }
        
//         vector<int>v(maxx+1,0);
//         for(auto &x:freq)
//         {
//             v[x]++;
//         }
        
//         int res=0;
//         for(int i=v.size()-1;i>0;i--)
//         {
//             if(!v[i])continue;
//             res+=(v[i]-1);
//             v[i-1]+=(v[i]-1);
//         }
        
        sort(freq.begin(),freq.end(),greater<int>());
    
        int res=0;
        bool f=0;
        for(int i=0;i<25;i++)
        {
            
            if(freq[i]>freq[i+1])continue;
            else
            {
                if(f)
                {
                    res+=freq[i+1];
                    freq[i+1]=0;
                    continue;
                }
                int t=freq[i+1];
               freq[i+1]=max(freq[i]-1,0);
                if(freq[i+1]==0)f=1;
                res+=(t-freq[i+1]);
            }
        }
        
        
        return res;
    }
};

