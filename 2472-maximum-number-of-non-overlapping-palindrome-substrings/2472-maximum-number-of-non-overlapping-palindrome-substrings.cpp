class Solution {
    vector<vector<int>>isPal;
    vector<int>dp;
    int helper(string &s,int i,int &k)
    {
        if(i==s.length())return 0;
        if(dp[i]!=-1)return dp[i];
        int res=helper(s,i+1,k);
        for(int j=i+k-1;j<s.length();j++)
        {
            if(isPal[i][j])
                res=max(res,1+helper(s,j+1,k));
        }
        return dp[i]=res;
    }
public:
    int maxPalindromes(string s, int k) {
        int n=s.length();
        if(k==1)return n;
        isPal=vector<vector<int>>(n,vector<int>(n,0));
        //cout<<n;
        
//         int res=0;
         //vector<pair<int,int>>v;
       dp=vector<int>(n,-1);
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                if(g==0)isPal[i][i]=1;
                else if(g==1)isPal[i][j]=(s[i]==s[j]);
                else isPal[i][j]=(s[i]==s[j])&(isPal[i+1][j-1]);
                if(g>=(k-1)&&isPal[i][j])
                {
                    //cout<<i<<" "<<j<<"\n";
                   // v.push_back({i,j});
                }
            }
        }
      
        // if(!v.size())return 0;
        // sort(v.begin(),v.end());
        // //for(auto &P:v)cout<<P.first<<" "<<P.second<<"\n";
        // vector<pair<int,int>>vv;
        // vv.push_back(v[0]);
        // for(int i=1;i<v.size();i++)
        // {
        //     if(v[i].first<=vv.back().second)vv.back().second=min(vv.back().second,v[i].second);
        //     else
        //         vv.push_back(v[i]);
        // }
        // return vv.size();
        
        return helper(s,0,k);
    }
};

/*

"sjbxiufnaanqkwsqswkqrcznzcddhtuhtthuttjfuufjtcfywgecegwyhhnnhtozczirynhhnyrire"
3
"fttfjofpnpfydwdwdnns"
2
"iqqibcecvrbxxj"
1


*/