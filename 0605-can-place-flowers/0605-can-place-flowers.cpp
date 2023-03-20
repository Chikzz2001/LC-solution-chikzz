class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int>v;
        v.push_back(-2);
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==1)
                v.push_back(i);
        }
        v.push_back(flowerbed.size()+1);
        int flowers=0;
        //for(auto &x:v)cout<<x<<" ";
        for(int i=0;i<v.size()-1;i++)
        {
            
            flowers+=(v[i+1]-v[i])/2>=1?((v[i+1]-v[i])/2-1):0;
        }
        return flowers>=n;
    }
};