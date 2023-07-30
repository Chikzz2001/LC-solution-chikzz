class Solution {
    int lps(string &a,string &b) {
        string l = b + "#" + a;
        
        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }
        return p[l.size()-1];
    }
public:
    string minimumString(string a, string b, string c) {
        vector<vector<int>>v={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
        vector<string>vv={a,b,c};
        
        string res;
        
        for(int i=0;i<6;i++) {
            string s=vv[v[i][0]];
            bool f=0;
            for(int j=0;j+vv[v[i][1]].length()<s.length();j++) {
                if(s.substr(j,vv[v[i][1]].length())==vv[v[i][1]]){f=1;break;}
            }
            if(!f) {
                int r=lps(s,vv[v[i][1]]);
                s+=vv[v[i][1]].substr(r);
            }
            
            f=0;
            for(int j=0;j+vv[v[i][2]].length()<s.length();j++) {
                if(s.substr(j,vv[v[i][2]].length())==vv[v[i][2]]){f=1;break;}
            }
            if(!f) {
                int r=lps(s,vv[v[i][2]]);
                s+=vv[v[i][2]].substr(r);
            }
            // cout<<i<<" "<<s<<"\n";
           if(res=="")res=s;
            else {
                if(s.length()<res.length())res=s;
                else if(s.length()==res.length())res=min(s,res);
            }
        }
        return res;
    }
};