class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        
        int l=0,r=1e9;
        while((r-l)>1) {
            int m=l+(r-l)/2;
            
            int prev=price[0];
            int tot=1;
            for(int i=1;i<price.size();i++) {
                if(price[i]-prev>=m) {
                    prev=price[i];
                    tot++;
                }
            }
            
            if(tot>=k)l=m;
            else r=m;
        }
        return l;
    }
};