#define ll long long
class Solution {
    const int M=1e9+7;
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        
        //x-coordinate--->{entry/exit,y-lower,y-upper}
        map<ll,set<vector<ll>>>x_line;
        //current y-coordinate ranges under cnsideration
        multiset<pair<ll,ll>>y_line;
        
        //entry:0 exit:1
        for(auto r:rectangles) {
            x_line[r[0]].insert({0,r[1],r[3]});
            x_line[r[2]].insert({1,r[1],r[3]});
        }
        
        //1-D line sweep
        auto area=[&](ll prev,ll x) {
            if(prev==-1)return 0;
            ll l=-1,r=-1;
            ll res=0;
            for(auto [yl,yu]:y_line) {
                if(yl>=l&&yl<=r) {
                    r=max(r,yu);
                }
                else if(yl>r) {
                    res=(res%M+((x-prev)%M*(r-l)%M)%M)%M;
                    l=yl,r=yu;
                }
            }
            res=(res%M+((x-prev)%M*(r-l)%M)%M)%M;
            return (int)res;
        };
        
        ll res=0,prev=-1;
        for(auto [x,args]:x_line) {
            ll ar=area(prev,x);
            res=(res%M+ar%M)%M;
            // cout<<x<<" "<<ar<<"\n";
            prev=x;
            for(auto a:args) {
                ll type=a[0],yl=a[1],yu=a[2];
                
                // cout<<x<<" "<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n";
                if(type==1) {
                    auto it=y_line.lower_bound({yl,yu});
                    y_line.erase(it);
                }
                else {
                    y_line.insert({yl,yu});
                }
            }
        }
        
        return res;
    }
};