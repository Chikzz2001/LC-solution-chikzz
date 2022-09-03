class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>v={1,2,3,4,5,6,7,8,9};
        
        for (int i=2;i<=n;i++) 
        {
            vector<int>vv;
            for (int &x:v) {
                int y=x%10;
                if (y+k<10)
                    vv.push_back(x*10+y+k);
                if (k>0&&y-k>=0)
                    vv.push_back(x*10+y-k);
            }
            v=vv;
        }
        return v;
        
    }
};