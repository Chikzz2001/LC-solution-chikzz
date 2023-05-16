class MagicDictionary {
    class TrieNode {
        public:
        TrieNode* links[26];
        bool end=0;
    };
    class Trie {
        TrieNode* root;
        public:
        Trie() {
            root=new TrieNode();
        }
        
        void insert(string &w) {
            TrieNode* node=root;
            for(char ch:w) {
                if(!node->links[ch-'a']) {
                    node->links[ch-'a']=new TrieNode();
                }
                node=node->links[ch-'a'];
            }
            node->end=1;
        }
        
        bool check(string &w) {
            TrieNode* node=root;
            return isvalid(w,0,root,0);
        }
        
        bool isvalid(string &w,int i,TrieNode* root,int c) {
            if(i==w.length())return root->end&&c==1;
            bool res=0;
            for(int j=0;j<26;j++) {
                if(root->links[j]) {
                    if(j!=w[i]-'a') {
                        if(c==1)continue;
                        else res|=isvalid(w,i+1,root->links[j],c+1);
                    }
                    else {
                        res|=isvalid(w,i+1,root->links[j],c);
                    }
                }
            }
            return res;
        }
    };
public:
    Trie trie;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(string s:dictionary) {
            trie.insert(s);
        }
    }
    
    bool search(string searchWord) {
        return trie.check(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */