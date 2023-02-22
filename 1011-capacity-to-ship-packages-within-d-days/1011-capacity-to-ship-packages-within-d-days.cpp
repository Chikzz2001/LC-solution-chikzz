class Solution {
public:
    int shipWithinDays(vector<int>& wt, int d) {
        int l=0,r=1e9;
        
        while((r-l)>1) {
            int m=l+r>>1;
            int D=1,S=0;
            bool ok=1;
            for(int i=0;i<wt.size();i++) {
                if(wt[i]>m){ok=0;break;}
                if(S+wt[i]>m) {
                    D++;
                    S=wt[i];
                }
                else S+=wt[i];
            }
            if(ok&&D<=d)r=m;
            else l=m;
        }
        
        return r;
    }
};