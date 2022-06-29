class RangeFreqQuery {
   // vector<vector<int>>m;
    map<int,vector<int>>freq;
    int maxx,minn;
public:
    RangeFreqQuery(vector<int>& arr) 
    {
//         maxx=*max_element(arr.begin(),arr.end());
//         minn=*min_element(arr.begin(),arr.end());
        int n=arr.size();
//         m=vector<vector<int>>(n,vector<int>(maxx+1,0));
        
//         m[0][arr[0]]++;
//         freq[arr[0]]++;
//         for(int i=1;i<n;i++)
//         {
//             // for(int j=0;j<=maxx;j++)
//             //     m[i][j]=m[i-1][j];
//            freq[arr[i]]++;
//            m[i][arr[i]]=freq[arr[i]];
//         }
        
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

/*

 4:2
 idx2=1;
 
*/