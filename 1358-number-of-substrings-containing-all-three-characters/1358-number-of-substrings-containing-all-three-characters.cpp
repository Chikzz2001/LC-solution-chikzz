class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>m;
        int i=0,j=0;
        int n=s.length();
        
        int res=0;
        while(j<n)
        {
            m[s[j]]++;
            
//             if(m.size()==3)
//                 res+=(n-j-1);
            
            while(i<j&&m.size()==3)
            {
                res+=(n-j);
                m[s[i]]--;
                if(m[s[i]]==0)m.erase(s[i]);
                i++;
            }
            
            j++;
        }
        
        return res;
    }
};

/*

acbbcac

*/