class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(),people.end());
        
        int n=people.size();
        vector<vector<int>>res(n,vector<int>(2,-1));
        
        for(int i=0;i<n;i++)
        {
            int c=people[i][1];
            for(int j=0;j<n;j++)
            {
                if(res[j][0]==-1&&c==0)
                {
                    res[j]=people[i];
                    break;
                }
                else if(res[j][0]==-1||res[j][0]>=people[i][0])c--;
            }
        }
        return res;
    }
};