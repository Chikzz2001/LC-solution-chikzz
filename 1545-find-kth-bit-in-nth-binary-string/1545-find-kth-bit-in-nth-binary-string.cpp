class Solution {
    string dp[21]={""};
    string dp2[21]={""};
    string f(string s,int n)
    {
        if(dp2[n]!="")return dp2[n];
        
        reverse(s.begin(),s.end());
        for(auto &x:s)
        {
            x=x=='1'?'0':'1';
        }
        return dp2[n]=s;
    }
    
    string generate(int n)
    {
        if(n==1)return dp[1]="0";
        if(dp[n]!="")return dp[n];
        return dp[n]=generate(n-1)+"1"+f(generate(n-1),n-1);
    }
public:
    char findKthBit(int n, int k) {
        
        string st=generate(n);
       // cout<<st;
        return st[k-1];
    }
};
