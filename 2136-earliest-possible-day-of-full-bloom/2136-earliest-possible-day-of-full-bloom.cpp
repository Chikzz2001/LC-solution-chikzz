class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        //1 2 2 2
        //  1 1 1 2 2
        //        1 1 1 1 2 2 2 2
        //0 1 2 3 4 5 6 7 8 9 
        //1 2 2 2
        //  1 1 1 1 2 2 2 2
        //          1 1 1 2 2
        
        int maxdays=-1,res=0;
        vector<vector<int>>v;
        for(int i=0;i<plantTime.size();i++)
            v.push_back({growTime[i],plantTime[i]});
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++)
        {
            res=max(res,maxdays+v[i][1]+v[i][0]);
            maxdays+=v[i][1];
        }
        return res+1;
    }
};


/*

1 1 1 2 2
      1 1 2
          1 1 2
              1 2 2

0 1 2 3 4 5 6 7 8 9


*/