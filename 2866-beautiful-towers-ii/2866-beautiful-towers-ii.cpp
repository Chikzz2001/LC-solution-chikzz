#define ll long long
#define ff first
#define ss second
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& h) {
        int n=h.size();
        ll pre[n],suf[n];
        
        vector<pair<ll,ll>>v;
        ll s=0;
        for(int i=0;i<n;i++) {
            ll c=1;
            while(v.size()&&v.back().ff>h[i]) {
                s-=(v.back().ff-h[i])*v.back().ss;
                c+=v.back().ss;
                v.pop_back();
            }
            s+=h[i];
            pre[i]=s;
            if(v.size()&&v.back().ff==h[i])v.back().ss+=c;
            else
            v.push_back({h[i],c});
        }
        
        v.clear();
        s=0;
        for(int i=n-1;i>=0;i--) {
            ll c=1;
            while(v.size()&&v.back().ff>h[i]) {
                s-=(v.back().ff-h[i])*v.back().ss;
                c+=v.back().ss;
                v.pop_back();
            }
            s+=h[i];
            suf[i]=s;
            if(v.size()&&v.back().ff==h[i])v.back().ss+=c;
            else
            v.push_back({h[i],c});
        }
        
        ll maxx=0;
        for(int i=0;i<n;i++) {
            // cout<<pre[i]<<" "<<suf[i]<<"\n";
            maxx=max(maxx,pre[i]+suf[i]-h[i]);
        }
        
        return maxx;
    }
};