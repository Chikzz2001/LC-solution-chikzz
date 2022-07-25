class Solution {
    class TrieNode
    {
        public:
        TrieNode* links[26];
        vector<int>idx;
    };
    
    class Trie
    {
        TrieNode* root;
        public:
        Trie()
        {
            root=new TrieNode();
        }
        
        void insert(string s,int id)
        {
            TrieNode* node=root;
            for(auto &ch:s)
            {
                if(!node->links[ch-'a'])
                    node->links[ch-'a']=new TrieNode();
                
                node=node->links[ch-'a'];
                node->idx.push_back(id);
            }
        }
        
        vector<int> search(string s)
        {
            TrieNode* node=root;
            for(int i=0;i<s.length();i++)
            {
                if(!node->links[s[i]-'a'])return {};
                node=node->links[s[i]-'a'];
            }
            return node->idx;
        }
    };
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        Trie trie;
        sort(products.begin(),products.end());
        for(int i=0;i<products.size();i++)
        {
            trie.insert(products[i],i);
        }
        
        string s;
        int len=searchWord.length();
        vector<vector<string>>res(len);
        
        for(int i=0;i<searchWord.length();i++)
        {
            s+=searchWord[i];
            vector<int>t=trie.search(s);
            for(int j=0;j<min(3,(int)t.size());j++)
            {
                res[i].push_back(products[t[j]]);
            }
        }
        
        return res;
    }
};