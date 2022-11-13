class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        int i=0,n=s.length();
        vector<string>v;
        for(int j=0;j<n;j++)
        {
            if(s[j]==' ')
            {
               if(i<j){v.push_back(s.substr(i,j-i));i=j+1;}
                else i++;
            }
        }
        string st;
        for(int i=v.size()-1;i>=0;i--)st+=v[i]+" ";
        st.pop_back();
        return st;
    }
};