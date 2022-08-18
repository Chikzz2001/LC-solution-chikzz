class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        for(auto &x:arr)m[x]++;
        vector<int>v;
        for(auto &[x,y]:m)v.push_back(y);
        sort(v.begin(),v.end(),greater<int>());
        int val=0;
        for(int i=0;i<v.size();i++)
        {
            val+=v[i];
            if(val>=(arr.size()+1)/2)
                return i+1;
        }
        return 0;
    }
};