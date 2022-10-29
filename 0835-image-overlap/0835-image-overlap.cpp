class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        //0,0 0,1 1,1 2,1
        //1,1 1,2 2,2
        
        //1,1-->1+1+1
        //1,2-->1
        //2,2-->1
        //1,0-->1
        //2,1-->1
        //0,0-->1
        //0,1-->1
        //we can perform a set of movements over certain rows and columns due to which the 
        //configuration of the first img will be modified and we will try to maximise the common number
        //of ones
        
        //we check by which modification we get maximum no. of overlapped ones
        //--->lets say 
        /*
        
            0 0 0       1 1 0
            0 1 1-----> 1 1 0-->we can shift the row:1 by -1 once then col:0 by -1 once-->we will get 3 
            1 1 0       1 0 0   common overlapping imgs
        
        */
        
        set<pair<int,int>>mat1,mat2;
        for(int i=0;i<img1.size();i++)
            for(int j=0;j<img1[0].size();j++)
                if(img1[i][j])mat1.insert({i,j});
        
        for(int i=0;i<img2.size();i++)
            for(int j=0;j<img2[0].size();j++)
                if(img2[i][j])mat2.insert({i,j});
            
        map<pair<int,int>,int>m;
        int res=0;
        for(auto &[a,b]:mat1)
        {
            for(auto &[c,d]:mat2)
            {
                m[{a-c,b-d}]++;
                res=max(res,m[{a-c,b-d}]);
            }
        }
        return res;
    }
};