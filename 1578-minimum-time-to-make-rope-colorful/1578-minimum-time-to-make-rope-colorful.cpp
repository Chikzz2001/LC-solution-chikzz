class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0,n=colors.length();
        
        for(int i=0;i<n-1;)
        {
            if(colors[i]==colors[i+1])
            {
                char x=colors[i];
                int maxx=0,sum=0;
                while(i<n&&colors[i]==x)
                {
                    sum+=neededTime[i];
                    maxx=max(maxx,neededTime[i]);
                    i++;
                }
                res+=sum-maxx;
            }
            else
                i++;
        }
        return res;
        
    }
};