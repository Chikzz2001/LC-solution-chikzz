class Solution {
    bool match(string& stamp,string& target,int idx) 
    {
        int skips=0;
        for (int i=0;i<stamp.length();i++)
        {
            char ch=target[i+idx];
            if (ch=='#') 
            {
                skips++;
            }
            else if(stamp[i]!=ch)
                return 0;
        }
        return skips!=stamp.length();
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        if (stamp.length()==target.length()) 
        {
            if (stamp==target)return {0};
            return {};
        }

        vector<int>res;
        bool is_match=1;
        while (is_match) 
        {
            is_match=0;
            for (int idx=target.length()-stamp.length();idx>=0;idx--) 
            {
                if (match(stamp,target,idx)) 
                {
                    is_match=1;
                    
                    res.push_back(idx);
                    for (int i=0;i<stamp.length();i++) 
                        target[idx+i]='#';
                }
            }
        }
        
        bool marked=0;
        for(int i=0;i<target.length();i++)
        {
            if(target[i]!='#')
            {
                marked=1;
                break;
            }
        }
        if (marked)return {};

        reverse(res.begin(),res.end());
        return res;
    }
};