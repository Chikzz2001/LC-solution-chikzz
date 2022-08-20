class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int>net(n+1,0);
        
        for(auto &shift:shifts)
        {
            int sh=(shift[2]?1:-1);
            net[shift[0]]=(net[shift[0]]+sh+26)%26;
            net[shift[1]+1]=(net[shift[1]+1]-sh+26)%26;
        }
        for(int i=1;i<n;i++)net[i]+=net[i-1];
        //0 0 0
        //1 1
        //for(auto &x:net)cout<<x<<" ";
        for(int i=0;i<n;i++)
        {
            //cout<<(net[i]+26)%26<<" ";
            s[i]='a'+(s[i]-'a'+net[i]+26)%26;
        }
        return s;
    }
};