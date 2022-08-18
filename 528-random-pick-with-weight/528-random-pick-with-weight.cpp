class Solution {
    vector<int>cummulative;
    int tot_wt=0;
public:
    Solution(vector<int>& w) {
        int n=w.size();
        cummulative=vector<int>(n);
        cummulative[0]=w[0];
        for(int i=1;i<n;i++)
        {
            cummulative[i]=cummulative[i-1]+w[i];
        }
        tot_wt=cummulative[n-1];
    }
    
    //3 17 18 25
    int pickIndex() {
        int ele=rand()%tot_wt;
        ele++;
        int lo=0,hi=cummulative.size()-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(cummulative[mid]>=ele)
            {
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        return lo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */