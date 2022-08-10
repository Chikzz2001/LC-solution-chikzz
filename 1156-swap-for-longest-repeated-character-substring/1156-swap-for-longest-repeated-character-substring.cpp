#define ff first
#define ss second
class Solution {
      map<char,int>m,mm;
    bool check()
    {
        if(mm.size()==1)return 1;
        if(mm.size()>2)return 0;
        auto it1=mm.begin();
        auto it2=it1;it2++;
        bool f=0;
        if((*it1).ss>=1&&(*it2).ss==1)f|=(m[(*it1).ff]>(*it1).ss);
        if((*it2).ss>=1&&(*it1).ss==1)f|=(m[(*it2).ff]>(*it2).ss);
        return f;
    }
public:
    int maxRepOpt1(string text) {
        for(auto &ch:text)m[ch]++;
        
        int i=0,j=0,n=text.length(),res=1;
        while(j<n)
        {
            mm[text[j]]++;
            while(i<j&&!check())
            {
                mm[text[i]]--;
                if(mm[text[i]]==0)mm.erase(text[i]);
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};
