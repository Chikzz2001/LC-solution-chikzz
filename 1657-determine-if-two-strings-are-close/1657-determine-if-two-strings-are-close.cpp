class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        if(n!=m)return 0;
        
        map<int,int>m1,m2;
        for(auto &x:word1)m1[x]++;
        for(auto &x:word2)m2[x]++;
        
        vector<int>v1,v2;
        for(auto &[x,y]:m1){if(!m2.count(x))return 0;v1.push_back(y);}
        for(auto &[x,y]:m2){if(!m1.count(x))return 0;v2.push_back(y);}
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        return v1==v2;
    }
};