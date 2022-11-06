class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1)
        {
            string res=s;
            for(int i=0;i<s.length();i++)
            {
                string t=s.substr(i)+s.substr(0,i);
                if(t.compare(res)<0)
                    res=t;
            }
            return res;
        }
        else{
            vector<char>a;
            for(char x:s)
                a.push_back(x);
            sort(a.begin(),a.end());
            s="";
            for(char x:a)
                s+=x;
            return s;
        }
    }
};