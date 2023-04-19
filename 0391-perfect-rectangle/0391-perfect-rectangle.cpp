class Solution {
    bool merge_interval(vector<vector<int>>& v) {
        if(v.size()==0)return 1;
        sort(v.begin(),v.end());
        vector<vector<int>>vv;
        vv.push_back(v[0]);
        for(int i=1;i<v.size();i++) {
            if(vv.back()[1]>v[i][0])return 0;
            if(vv.back()[1]==v[i][0])vv.back()[1]=max(vv.back()[1],v[i][1]);
            else vv.push_back(v[i]);
        }
        v=vv;
        return 1;
    }
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        //check for totality in y-coordinates
        map<int,vector<vector<int>>>x_line;
        
        //entry:0 exit:1
        for(auto r:rectangles) {
            x_line[r[0]].push_back({0,r[1],r[3]});
            x_line[r[2]].push_back({1,r[1],r[3]});
        }
        
        vector<vector<int>>y_entry,y_exit;
        int c=0;
        for(auto [x,args]:x_line) {
            y_entry.clear();
            y_exit.clear();
            for(auto a:args) {
                int type=a[0],yl=a[1],yu=a[2];
                if(type==0) {
                    y_entry.push_back({yl,yu});
                }
                else {
                    y_exit.push_back({yl,yu});
                }
            }
            bool entry=merge_interval(y_entry);
            bool exit=merge_interval(y_exit);
            // cout<<x<<" "<<entry<<"\n";
            if(!entry||!exit)return 0;
            if(c==0||c==x_line.size()-1) {
                c++;continue;
            }
            if(y_entry!=y_exit)return 0;
            c++;
        }
        return 1;
    }
};