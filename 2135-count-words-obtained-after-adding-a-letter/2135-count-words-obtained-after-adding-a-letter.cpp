class Solution {
public:
    int wordCount(vector<string>& sW, vector<string>& tW) 
    {
        unordered_map<int,unordered_set<string>>m;
        
        for(auto &w:sW)
        {
            int n=w.length();
            sort(w.begin(),w.end());
            m[n].insert(w);
        }
        
        int res=0;
        for(int i=0;i<tW.size();i++)
        {
            string s=tW[i];
            int n=s.length();
            if(!m.count(n-1))continue;
            sort(s.begin(),s.end());
            for(int i=0;i<n;i++)
            {
                string st=s.substr(0,i)+s.substr(i+1);
                if(m[n-1].count(st))
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};