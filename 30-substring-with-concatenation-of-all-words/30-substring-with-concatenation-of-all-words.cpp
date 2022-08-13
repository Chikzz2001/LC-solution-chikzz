class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.length(),len=words[0].length(),k=len*words.size();
        
        map<string,int>m;
        for(auto &w:words)
            m[w]++;
        
        int size=m.size();
        vector<int>res;
        for(int i=0;i<=n-k;i++)
        {
            bool f=1;
            int c=0;
             map<string,int>t=m; 
            for(int j=i;j<i+k;j+=len)
            {
               string ss=s.substr(j,len);
               if(t.count(ss)&&t[ss]>0)
               {
                   t[ss]--;
                   if(t[ss]==0)c++;
               }
               else
               {
                   f=0;
                   break;
               }
            }
            //cout<<i<<"-->"<<(f?"true":"false")<<"\n";
            if(f&&c==size)
                res.push_back(i);
        }
        return res;
    }
};