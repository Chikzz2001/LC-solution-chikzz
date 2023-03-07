#define ll long long
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l=0,r=1e15;
        ll s=0;
        while((r-l)>1) {
            ll m=l+(r-l)/2;
            
            ll t=0;bool ok=0;
            for(int i=0;i<time.size();i++) {
                t+=m/time[i];
                if(t>=totalTrips){ok=1;break;}
            }
            
            if(ok)r=m;
            else l=m;
        }
        return r;
    }
};