class RangeFreqQuery {
    map<int,vector<int>>freq;
public:
    RangeFreqQuery(vector<int>& arr) 
    {
        int n=arr.size();

        for(int i=0;i<n;i++)
            freq[arr[i]].push_back(i);
    }
    
    int query(int l, int r, int val) 
    {
        if(!freq.count(val))return 0;
        int idx2=upper_bound(freq[val].begin(),freq[val].end(),r)-freq[val].begin();
        idx2--;
        int idx1=lower_bound(freq[val].begin(),freq[val].end(),l)-freq[val].begin();
        idx1--;
        
        return idx2-idx1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */