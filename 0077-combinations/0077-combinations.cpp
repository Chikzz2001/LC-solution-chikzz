class Solution 
{
    vector<vector<int>>res;
    vector<int>temp;
    int N;
    void helper(int start,int k)
    {
        if(k==0)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=start;i<=N;i++)
        {
            temp.push_back(i);
            helper(i+1,k-1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) 
    {
        N=n;
        helper(1,k);
        return res;
    }
};