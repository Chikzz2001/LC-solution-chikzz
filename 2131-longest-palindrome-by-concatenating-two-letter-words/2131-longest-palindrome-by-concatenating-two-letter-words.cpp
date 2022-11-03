class Solution {
public:
    int longestPalindrome(vector<string>& ss) {
        //we store the count of strings with different characters in mp1 and the other in mp2
        unordered_map<string,int>mp1,mp2;
        for(auto &s:ss)
        {
            if(s[0]==s[1])mp2[s]++;
            else
                mp1[s]++;
        }
        //the final ans is stored in len
        int len=0;
        
        //for mp1 we calculate if the palindrome exists and we take the min of the count and delete the palindrome from the map as 
        //we do not want double count
        for(auto &x:mp1)
        {
            string st="";
            st+=x.first[1];
            st+=x.first[0];
            if(mp1.count(st))
            {
                len+=4*min(mp1[x.first],mp1[st]);
                mp1.erase(st);
            }
        }
    
        bool f=1;
        //for similar character strings we can take only one set of odd count string completely and for other counts we have to leave one   
        //string but for strings with even count we consider all counts. 
        for(auto &x:mp2)
        {
            if(x.second&1){
                if(f)
            {len+=x.second*2;f=0;}
            else
                len+=(x.second/2)*4;
                           }
            else
                len+=x.second*2;
        }
        return len;
    }
};
