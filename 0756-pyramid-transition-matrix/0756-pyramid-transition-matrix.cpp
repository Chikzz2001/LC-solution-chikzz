class Solution {
    map<string,vector<string>>m;
    unordered_map<string,bool>dp;
    
    bool ispossible(string &s,int len,int idx,string temp)
    {
        if(s.length()==1)return 1;
        
        string l=to_string(len);
        string id=to_string(idx);
        string key=s+"#"+temp+"#"+l+"#"+id;
        
        if(dp.count(key))
            return dp[key];
        
        if(temp.length()==len-1)
        {
            return dp[key]=ispossible(temp,len-1,0,"");
        }
        
        for(auto &x:m[s.substr(idx,2)])
        {
            if(ispossible(s,len,idx+1,temp+x))
                return dp[key]=1;
        }
        return dp[key]=0;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n=allowed.size();
        
        for(int i=0;i<n;i++)
        {
            m[allowed[i].substr(0,2)].push_back(allowed[i].substr(2));
        }
        
        int len=bottom.length();
        return ispossible(bottom,len,0,"");
    }
};