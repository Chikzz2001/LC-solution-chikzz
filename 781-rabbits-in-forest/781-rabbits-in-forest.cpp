class Solution {
public:
    int numRabbits(vector<int>& ans) 
    {
        unordered_map<int,int>m;
        for(auto &x:ans)
            m[x]++;
        
        int res=0;
        for(auto &[x,y]:m)
        {
           if(y%(1+x))
              res+=(y/(1+x)+1)*(1+x);
           else
                res+=y;
        }
        return res;
    }
};
