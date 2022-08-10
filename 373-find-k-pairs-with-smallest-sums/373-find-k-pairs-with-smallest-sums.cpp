class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>pQ;
        
        for(int i=0;i<nums2.size();i++)
        {
            pQ.push({-(nums1[0]+nums2[i]),{0,i}});
        }
        
        vector<vector<int>>res;
        while(!pQ.empty()&&k--)
        {
            auto [sum,P]=pQ.top();
            pQ.pop();
            auto [i,j]=P;
            res.push_back({nums1[i],nums2[j]});
            if(i<nums1.size()-1)
            pQ.push({-(nums1[i+1]+nums2[j]),{i+1,j}});
        }
        return res; 
    }
};