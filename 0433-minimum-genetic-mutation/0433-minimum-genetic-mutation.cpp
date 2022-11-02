class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        set<string>genes;
        
        for(auto &g:bank)
            genes.insert(g);
        
        if(!genes.count(end))return -1;
        char gene[4]={'A','C','G','T'};
        
        int n=start.length();
        
        queue<string>Q;
        Q.push(start);
        
        set<string>vis;
        vis.insert(start);
        
        int level=0;
        while(!Q.empty())
        {
            int size=Q.size();
            while(size--)
            {
                string curr=Q.front();
                Q.pop();
                
                if(curr==end)return level;
                
                for(int i=0;i<n;i++)
                {
                    char ch=curr[i];
                    for(int j=0;j<4;j++)
                    {
                        if(ch!=gene[j])curr[i]=gene[j];
                        if(!vis.count(curr)&&genes.count(curr))
                        {
                            if(curr==end)return level+1;
                            Q.push(curr);
                            vis.insert(curr);
                        }
                    }
                    curr[i]=ch;
                }
            }
            level++;
        }
        return -1;
    }
};