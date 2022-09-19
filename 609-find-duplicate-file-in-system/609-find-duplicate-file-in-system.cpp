class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<string>>m;
        for(auto &x:paths)
        {
            stringstream S(x);
            string w;
            int i=0;
            string dir,file,content;
            while(S>>w)
            {
                if(!i)dir=w;
                else
                {
                    for(int i=0;i<w.length();i++)
                    {
                        if(w[i]=='(')
                        {
                            file=w.substr(0,i);
                            content=w.substr(i+1,w.length()-1);
                            break;
                        }
                    }
                    m[content].push_back(dir+"/"+file);
                }
                i++;
            }
        }
        vector<vector<string>>res;
        for(auto &[x,y]:m)
        {
            if(y.size()>1)
            res.push_back(y);
        }
        return res;
    }
};