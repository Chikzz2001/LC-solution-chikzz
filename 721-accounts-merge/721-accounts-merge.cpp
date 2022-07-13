class Solution {
    map<string,int>size;
    map<string,string>par;
    void join(string a,string b)
    {
        string pa=find(a);
        string pb=find(b);
        if(pa!=pb)
        {
            if(size[pa]>=size[pb])
            {
                par[pb]=pa;
                size[pa]+=size[pb];
            }
            else
            {
                par[pa]=pb;
                size[pb]+=size[pa];
            }
        }
    }
    string find(string x)
    {
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        map<string,string>store;
        for(auto &acc:accounts)
        {
            string name=acc[0];
            for(int i=1;i<acc.size();i++)
            {store[acc[i]]=name;size[acc[i]]=1;par[acc[i]]=acc[i];}
        }
        
        // for(auto &[x,y]:par)
        //     cout<<x<<"-->"<<y<<"\n";
        
        for(auto &acc:accounts)
        {
            for(int i=1;i<acc.size()-1;i++)
                join(acc[i],acc[i+1]);
        }
        
        map<string,vector<string>>m;
        for(auto &[s,name]:store)
        {
            m[find(s)].push_back(s);
        }
        
        // for(auto &[x,y]:par)
        //     cout<<x<<"-->"<<y<<"\n";
        vector<vector<string>>res;
        for(auto &[parent,mails]:m)
        {
            vector<string>temp;
            temp.push_back(store[parent]);
            for(auto &mail:mails)
                temp.push_back(mail);
            res.push_back(temp);
        }
        
        return res;
    }
};