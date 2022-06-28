class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int>freq(26,0);
         int maxx=0;
        for(auto &ch:s)
        {
            freq[ch-'a']++;
            maxx=max(freq[ch-'a'],maxx);
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
        
        // for(int i=0;i<26;i++)
        //     cout<<freq[i]<<" ";
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
                    //cout<<i<<" "<<res<<"\n";
                    continue;
                }
                int t=freq[i+1];
               freq[i+1]=max(freq[i]-1,0);
                if(freq[i+1]==0)f=1;
                res+=(t-freq[i+1]);
                //cout<<i<<" "<<res<<"\n";
            }
        }
        
        
        return res;
    }
};

//3 2 2 1 1 1
//3 2 1 0 0 0

//2 2 2
//2 1 

//"nhgffkjjlnglnegfmcmjamdgjdf"
//4 3 2 1 0 0 0 0 0 0 0 0
//4 4 4 3 3 2 2 1 1 1 1 1
//1 2 2 3 2 2 1 1 1 1 1

/*

"abcabc"
"bbcebab"
"nhgffkjjlnglnegfmcmjamdgjdf"

*/