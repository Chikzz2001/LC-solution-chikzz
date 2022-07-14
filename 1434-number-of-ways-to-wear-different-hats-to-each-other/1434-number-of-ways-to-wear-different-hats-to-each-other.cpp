#define ll long long int
class Solution {
    const int M=1e9+7;
//     map<pair<ll,ll>,ll>dp;
//     ll helper(vector<vector<int>>& hats,int i,ll mask)
//     {
//         if(i==hats.size())
//             return 1;
        
//         if(dp.count({i,mask}))
//             return dp[{i,mask}];
        
//         ll res=0;
//         for(auto &x:hats[i])
//         {
//             if(!(mask&(1LL<<x)))
//                {
//                    mask|=(1LL<<x);
//                    res=res%M+helper(hats,i+1,mask)%M;
//                    mask^=(1LL<<x);
//                }
//         }
//         return dp[{i,mask}]=res%M;       
//     }
    
  ll dp[1<<11][41];  
    int N;
    ll helper(vector<vector<int>>& users,int i,int &mask)
    {
        if(i==users.size())
            return mask==(1<<N)-1?1:0;
        
        if(dp[mask][i]!=-1)
            return dp[mask][i];
        
        if(!users[i].size())return dp[mask][i]=helper(users,i+1,mask)%M;
        
        ll res=0;
        res=res%M+helper(users,i+1,mask)%M;
        for(auto &x:users[i])
        {
            if(!(mask&(1<<x)))
            {
                mask|=(1<<x);
                res=res%M+helper(users,i+1,mask)%M;
                mask^=(1<<x);
            }
        }
        return dp[mask][i]=res%M;
    }
public:
    int numberWays(vector<vector<int>>& hats)
    {
        // ll mask=0;
        // return helper(hats,0,mask)%M;
        N=hats.size();
        vector<vector<int>>users(41);
        int i=0;
        for(auto &h:hats)
        {
            for(auto &x:h)
                users[x].push_back(i);
            i++;
        }
        
        // for(int i=0;i<41;i++)
        // {
        //     cout<<i<<"-->";
        //     for(auto &x:users[i])
        //         cout<<x<<" ";
        //     cout<<"\n";
        // }
        
        int mask=0;
        memset(dp,-1LL,sizeof(dp));
        return helper(users,1,mask)%M;
    }
};

/*

1-->
2
3-->0,1
4-->
5-->1,2

*/