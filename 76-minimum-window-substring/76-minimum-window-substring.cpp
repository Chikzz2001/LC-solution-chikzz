class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mt,ms;
        for(auto &ch:t)
            mt[ch]++;
        
        int req=mt.size();
        
        int i=0,j=0,obt=0;
        int n=s.length();
        
        vector<int>res(2,-1);//res[0]=start_idx,res[1]=len
        while(j<n)
        {
            ms[s[j]]++;
            
            if(ms[s[j]]==mt[s[j]])obt++;
            
            while(i<=j&&obt==req)
            {
                if(res[0]==-1||res[1]>(j-i+1))
                {
                    res[0]=i,res[1]=(j-i+1);
                }
                ms[s[i]]--;
                if(ms[s[i]]<mt[s[i]])obt--;
                i++;
            }
            
            j++;
        }
        
        if(res[0]==-1)return "";
        return s.substr(res[0],res[1]);
    }
};