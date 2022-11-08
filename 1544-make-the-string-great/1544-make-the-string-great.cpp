class Solution {
public:
    string makeGood(string s) {
        //string st;
//         if(s.size()==1||s.size()==0)return s;
//     bool f=0;
//         while(!f){
//         for(int i=0;i<=s.length()-2;i++)
//         {
//             if(abs(s[i+1]-s[i])==32)
//             {
//                 s=s.substr(0,i)+s.substr(i+2);
//                 i--;
//             }
//             if(s.length()==0||s.length()==1)break;
//                 }
//             if(s.size()>1){bool check=0;
//             for(int i=0;i<=s.size()-2;i++)
//             {
//                   if(abs(s[i+1]-s[i])==32)
//             {check=1;
//             break;
//             }
//             }if(!check)
//                 f=!f;}
//             else break;
       
//     }
//          return s;
        
        vector<char>st;
        st.push_back(s[0]);
        int i=1;
        while(i<s.length())
        {
            if(st.empty()||abs(st.back()-s[i])!=32)
                st.push_back(s[i++]);
            else
            {
                st.pop_back();
                i++;
            }
        }
        string ss="";
    
        for(auto &x:st)
            ss+=x;
        
        return ss;
    }
};