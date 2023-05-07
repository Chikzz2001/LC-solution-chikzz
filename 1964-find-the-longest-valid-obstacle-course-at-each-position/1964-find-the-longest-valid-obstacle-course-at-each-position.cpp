class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>res;
        vector<int>LIS;
        LIS.push_back(obstacles[0]);
        res.push_back(1);
        for(int i=1;i<obstacles.size();i++)
        {
            if(LIS.back()<=obstacles[i])
            {
                LIS.push_back(obstacles[i]);
                res.push_back(LIS.size());
            }
            else
            {
                int idx=upper_bound(LIS.begin(),LIS.end(),obstacles[i])-LIS.begin();
                res.push_back(idx+1);
                LIS[idx]=obstacles[i];
            }
        }
        return res;
    }
};