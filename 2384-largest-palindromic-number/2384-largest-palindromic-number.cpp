class Solution {
public:
    string largestPalindromic(string num) {
        map<char,int>m;
        for(auto &x:num)m[x]++;
        
        bool f=0;
        string res;
        vector<char>v;
        vector<char>er;
        for(auto &[x,y]:m)
        {
            //cout<<x<<" "<<y;
            if((y&1))
            {
              v.push_back(x);
            }
            y/=2;
            if(!y)er.push_back(x);
        }
        for(auto &x:er)m.erase(x);
        if(v.size())
        {
            sort(v.begin(),v.end());
            res+=v.back();
        }
        //cout<<m['0'];
        if(m.size()==1&&(*m.begin()).first=='0')m.erase('0');
        for(auto &[x,y]:m)
        {
            res.append(y,x);
        }
        reverse(res.begin(),res.end());
         for(auto &[x,y]:m)
        {
            res.append(y,x);
        }
        return res.empty()?"0":res;
    }
};