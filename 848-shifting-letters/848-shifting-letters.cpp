class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        int n=shifts.size();
        vector<int>pre(n);
        pre[n-1]=shifts[n-1]%26;
        for(int i=n-2;i>=0;i--)
        {
            pre[i]=(shifts[i]%26+pre[i+1])%26;
        }
        
        //for(int i=0;i<n;i++)cout<<pre[i]<<" ";
        string res(n,'#');
        
        for(int i=0;i<n;i++)
        {
            res[i]='a'+(s[i]-'a'+pre[i])%26;
        }
        
        return res;
    }
};