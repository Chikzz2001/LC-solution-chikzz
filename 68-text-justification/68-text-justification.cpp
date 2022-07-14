class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<vector<string>>temp;
        int width=0;
        vector<string>t;
        for(int i=0;i<words.size();i++)
        {
            if(width+words[i].length()>maxWidth)
            {
                temp.push_back(t);
                t.clear();
                t.push_back(words[i]);
                width=words[i].length()+1;
            }
            else
            {
                t.push_back(words[i]);
                width+=words[i].length()+1;
            }
        }
        if(t.size())
            temp.push_back(t);
        
        vector<string>res;
        for(int j=0;j<temp.size()-1;j++)
        {
            auto x=temp[j];
            if(x.size()==1)
            {
                string s=x[0];
                int len=s.length();
                  if(maxWidth-len>0)
                s.append(maxWidth-len,' ');
                res.push_back(s);
                continue;
            }
            int spaces=maxWidth;
            for(auto &y:x)
                spaces-=y.length();
            int even=spaces/(x.size()-1);
            int extra=spaces%(x.size()-1);
            string s;
            for(int i=0;i<x.size()-1;i++)
            {
                s+=x[i];
                s.append(even,' ');
                if(extra-->0)s+=" ";
            }
            s+=x.back();
            res.push_back(s);
        }
        string s;
        for(auto &y:temp.back())
            s+=y+" ";
        s.pop_back();
        int len=s.length();
        if(maxWidth-len>0)
        s.append(maxWidth-len,' ');
        res.push_back(s);
        return res;
    }
};