class Solution {
    bool isPalin(string a,int s,int e)
    {
        while(s<e)
        {
            if(a[s]!=a[e])return 0;
            s++,e--;
        }
        return 1;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        unordered_map<string,int>idx;
        for(int i=0;i<words.size();i++)idx[words[i]]=i;
        sort(words.begin(),words.end(),[&](const string &a,const string &b)
             {
                 return a.length()<b.length();
             });
        
        //s lls abcd dcba sssll
        //for(auto &x:words)cout<<x<<"#";
        vector<vector<int>>res;
        set<pair<int,int>>S;
        unordered_map<string,int>m,mm;
        for(int i=0;i<words.size();i++)
        {
            if(m.count("")&&isPalin(words[i],0,words[i].length()-1))
            {
                S.insert({idx[""],idx[words[i]]});
                S.insert({idx[words[i]],idx[""]});
            }
            string s;
            for(int j=0;j<words[i].length();j++)
            {
                s+=words[i][j];
                if(m.count(s)&&isPalin(words[i],j+1,words[i].length()-1))
                {
                    S.insert({idx[words[i]],m[s]});
                    if(j+1>words[i].length()-1)
                        S.insert({m[s],idx[words[i]]});
                }
            }
             s="";
             string temp=words[i];
             reverse(words[i].begin(),words[i].end());
            for(int j=0;j<words[i].length();j++)
            {
                s+=words[i][j];
                
                if(mm.count(s)&&isPalin(words[i],j+1,words[i].length()-1))
                {
                    S.insert({mm[s],idx[temp]});
                }
            }
            
            m[words[i]]=idx[temp];
            mm[temp]=idx[temp];
        }
        for(auto &x:S)
            res.push_back({x.first,x.second});
        return res;
    }
};