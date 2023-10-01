class Solution {
    int res=0;
    void remove(string &s,string ss,int val) {
        string temp;
        for(int i=0;i<s.length();i++) {
            if(s[i]==ss[1]) {
                if(temp.size()&&temp.back()==ss[0]) {
                    res+=val;
                    temp.pop_back();
                }
                else temp+=s[i];
            }
            else temp+=s[i];
        }
        s=temp;
    }
public:
    int maximumGain(string s, int x, int y) {
       if(y>x) {
           remove(s,"ba",y);
           remove(s,"ab",x);
       }
        else {
           remove(s,"ab",x);
           remove(s,"ba",y);
        }
        return res;
    }
};