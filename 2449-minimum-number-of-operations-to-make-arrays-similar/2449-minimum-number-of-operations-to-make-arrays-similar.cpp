#define ll long long int
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        //6 8 12
        //2 10 14
        //+4 -2 -2
        
        
        //1 5       2
        //1 3       4
        
        vector<int>oddn,evenn,oddt,event;

        for(auto &x:nums)
        {
            if(x&1)oddn.push_back(x);
            else
                evenn.push_back(x);
        }
         for(auto &x:target)
        {
            if(x&1)oddt.push_back(x);
            else
                event.push_back(x);
        }
        
        sort(oddn.begin(),oddn.end());
        sort(evenn.begin(),evenn.end());
        sort(oddt.begin(),oddt.end());
        sort(event.begin(),event.end());
        
        ll res=0;
        for(int i=0;i<oddn.size();i++)
        {
            if(oddn[i]>oddt[i])res+=(oddn[i]-oddt[i])/2;
        }
        for(int i=0;i<evenn.size();i++)
        {
            if(evenn[i]>event[i])res+=(evenn[i]-event[i])/2;
        }
        return res;
    }
};