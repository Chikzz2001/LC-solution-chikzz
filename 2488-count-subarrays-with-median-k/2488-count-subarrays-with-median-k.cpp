class Solution {
public:
    int countSubarrays(vector<int>& v, int k) {
        
        /*
            -1 -1 -1 0 1
            0-->1
            -1 -2 -3 -3 -2
            0-->i
            0-->j
            0-->k sum=X we get X again at l
            i+1 to l=j+1 to l=k+1 to l have sum 0
        */
        int beg=-1;
        for(int i=0;i<v.size();i++){if(v[i]<k)v[i]=-1;else if(v[i]>k)v[i]=1;else {beg=i;v[i]=0;}}
        int res=0;
        map<int,int>m;
        m[0]=1;
        int pre=0;
        for(int i=0;i<v.size();i++)
        {
            pre+=v[i];
            //cout<<pre<<" ";
            if(i>=beg&&m.count(pre))res+=m[pre];
            if(i>=beg&&m.count(pre-1))res+=m[pre-1];
            if(i<beg)m[pre]++;
        }
        return res;
    }
};