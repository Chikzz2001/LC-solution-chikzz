#define lli long long int
#define min(a,b) a<b?a:b

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {

        //4 1 5 20 3
        //4 2 10 20 6--->minn=2
        //20 10 6 4 2
        //18 8  4
        //10 5  
        priority_queue<int>pq;
        
        int minn=INT_MAX;
        
        for(auto &it:nums)
        {
            if(it&1)
                it*=2;
            
            minn=min(minn,it);
            
            pq.push(it);
        }
        
        int diff=INT_MAX;
        
        while(pq.top()%2==0)
        {
            int maxx=pq.top();
            pq.pop();
            
            diff=min(diff,maxx-minn);
            minn=min(maxx/2,minn);
            pq.push(maxx/2);
        }
        
        return min(diff,pq.top()-minn);
    }
};