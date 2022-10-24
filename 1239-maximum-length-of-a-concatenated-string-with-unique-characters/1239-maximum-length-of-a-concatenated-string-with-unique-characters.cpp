#define max(a,b) a>b?a:b

class Solution {
    int freq[26];
    int maxx=0;
    //string temp="";
    void checkAllCombinations(vector<string>& inp,int idx,string temp)
    {
        if(idx==inp.size())
        {
            //cout<<temp<<"\n";
            maxx=max(maxx,temp.length());
            return;   
        }
        
        int f[26];
        fill(f,f+26,0);
        for(auto &x:inp[idx])
            f[x-'a']++;
        
        for(int i=0;i<26;i++)
        {
            if(f[i]&&freq[i])
            {
                checkAllCombinations(inp,idx+1,temp);
                return;
            }
        }
        
        checkAllCombinations(inp,idx+1,temp);
        for(int i=0;i<26;i++)
            freq[i]+=f[i];
    
        checkAllCombinations(inp,idx+1,temp+inp[idx]);
        
        for(int i=0;i<26;i++)
            freq[i]-=f[i];
    }
    
    bool hasUniqueChar(string s)
    {
        int a[26];
        fill(a,a+26,0);
        for(auto &ch:s)
            a[ch-'a']++;
        
        for(auto &it:a)
        {
            if(it>1)return 0;
        }
        return 1;
    }
    
public:
    int maxLength(vector<string>& arr) {
        
        string s="";
        vector<string>filter;
        for(auto &x:arr)
        {
            if(hasUniqueChar(x))
               filter.push_back(x); 
        }
        checkAllCombinations(filter,0,s);
        
        return maxx;
    }
};