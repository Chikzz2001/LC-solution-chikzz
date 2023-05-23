class KthLargest {
//     int K;
//     multiset<int>s;
// public:
//     KthLargest(int k, vector<int>& nums) {
//         K=k;
//         for(auto &it:nums)
//             s.insert(it);
    
//     }
    
//     int add(int val) {
//         s.insert(val);
//         auto it=s.end();
//         int n=K;
//         while(n--)it--;
//         return *it;
//     }
    
        priority_queue<int, vector<int>, greater<int>> pq;
    int size;
     public:
    KthLargest(int k, vector<int> nums) {
        size=k;
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */