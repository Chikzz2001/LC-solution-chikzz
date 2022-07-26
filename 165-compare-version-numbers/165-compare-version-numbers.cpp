class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1p=0,v2p=0;
        int v1len=version1.length();
        int v2len=version2.length();
        
        int n1=0,n2=0;
        while(v1p<v1len||v2p<v2len)
        {
            while(v1p<v1len&&version1[v1p]!='.')
            {
                n1=n1*10+(version1[v1p]-'0');
                v1p++;
            }
            
            while(v2p<v2len&&version2[v2p]!='.')
            {
                n2=n2*10+(version2[v2p]-'0');
                v2p++;
            }
            
            if(n1<n2)return -1;
            if(n1>n2)return 1;
            n1=0,n2=0;
            v1p++,v2p++;
        }
        return 0;
    }
};