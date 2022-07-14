class Solution {
map<int,int>pair;
vector<vector<string>>dp;
string helper(string st,int s,int e)
{
if(dp[s][e]!="#")
return dp[s][e];
for(int i=s;i<=e;i++)
{
if(st[i]=='(')
{
string x=helper(st,i+1,pair[i]-1);
reverse(x.begin(),x.end());
string res=st.substr(s,i-s)+x+helper(st,pair[i]+1,e);
return dp[s][e]=res;
}
}
string res=st.substr(s,e-s+1);
return dp[s][e]=res;
}
public:
string reverseParentheses(string s)
{
stack<int>st;
for(int i=0;i<s.length();i++)
{
if(s[i]=='(')
st.push(i);
else if(s[i]==')')
{
pair[st.top()]=i;
st.pop();
}
}
int n=s.length();
dp=vector<vector<string>>(n,vector<string>(n,"#"));
return helper(s,0,n-1);
}
};