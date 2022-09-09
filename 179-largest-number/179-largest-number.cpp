class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<string>v;
        for(auto &x:nums)
        {
            v.push_back(to_string(x));
        }
        sort(v.begin(),v.end(),[&](const string& s1,const string& s2)
             {
                 return s1+s2>s2+s1;
             });
        
        string res;
        for(auto &x:v)res+=x;
        return res[0]=='0'?"0":res;
    }
};