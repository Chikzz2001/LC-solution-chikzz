#define ll long long
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<set<string>>v(26);
        
        for(string s:ideas) 
            v[s[0]-'a'].insert(s.substr(1));
            
            ll res=0;
            for(int i=0;i<26;i++) {
                for(int j=i+1;j<26;j++) {
                    ll r1=0,r2=0;
                    //[i,j] j>i so i!=j always now we check for certain postfix if it starts with
                    //both 'a'+i and 'a'+j then we can swap it and make a valid pair
                    for(string s:v[i]) {
                        if(!v[j].count(s))r1++;
                    }
                    for(string s:v[j]) {
                        if(!v[i].count(s))r2++;
                    }
                    res+=r1*r2;
                }
            }
        return 2*res;
    }
};