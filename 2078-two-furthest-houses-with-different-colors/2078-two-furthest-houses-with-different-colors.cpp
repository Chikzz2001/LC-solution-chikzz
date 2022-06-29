#define ff first
#define ss second
class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        map<int,pair<int,int>>m;
        for(int i=0;i<colors.size();i++)
        {
            int c=colors[i];
            if(m.count(c))
                m[c].ss=i;
            else
            m[c]={i,-1};
        }
        
        int maxx=0;
        for(auto &[x,P]:m)
        {
            for(auto &[y,p]:m)
            {
                if(x>=y)continue;
                auto [f1,s1]=P;
                auto [f2,s2]=p;
                maxx=max(maxx,abs(f1-f2));
                if(s1!=-1)
                {
                    maxx=max(maxx,abs(f2-s1));
                }
                if(s2!=-1)
                {
                    maxx=max(maxx,abs(f1-s2));
                }
                if(s1!=-1&&s2!=-1)
                    maxx=max(maxx,abs(s1-s2));
            }
        }
        return maxx;
    }
};