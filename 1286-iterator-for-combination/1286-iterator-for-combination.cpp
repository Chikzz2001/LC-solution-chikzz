class CombinationIterator {
    vector<int>v;
    string S;
    int N;
    void update(int idx)
    {
        if(++v[idx]!=N-(v.size()-idx-1))
            return;
        
        if(idx==0)return;
        update(idx-1);
        v[idx]=1+v[idx-1];
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        v=vector<int>(combinationLength,0);
        for(int i=0;i<combinationLength;i++)
            v[i]=i;
        S=characters;
        N=characters.length();
    }
    
    string next() {
        // return "";
        string res;
        for(auto &x:v)res+=S[x];
        
        update(v.size()-1);
        return res;
    }
    
    bool hasNext() {
        // return 1;
        return v[0]<=(N-v.size());
    }
};

/*

["CombinationIterator","hasNext","next","hasNext","hasNext","next","next","hasNext","hasNext","hasNext","hasNext"]
[["chp",1],[],[],[],[],[],[],[],[],[],[]]

["CombinationIterator","hasNext","hasNext","hasNext","next","hasNext","next","next","next","hasNext","next"]
[["gkosu",3],[],[],[],[],[],[],[],[],[],[]]


gks
*/