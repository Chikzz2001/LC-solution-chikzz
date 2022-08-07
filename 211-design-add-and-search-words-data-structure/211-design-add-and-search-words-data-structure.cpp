struct TrieNode{
	TrieNode* links[26];
    bool end=0;
};

class WordDictionary 
{
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node=root;
        for(auto &ch:word)
        {
            if(!node->links[ch-'a'])
                node->links[ch-'a']=new TrieNode();
            node=node->links[ch-'a'];
        }
        node->end=1;
    }
    
    bool dfs(string& word,int i,TrieNode* node)
    {
       if(i==word.length())return node->end;
        
        if(word[i]=='.')
        {
            for(char j=0;j<26;j++)
            {
                if(node->links[j]&&dfs(word,i+1,node->links[j]))
                    return 1;
            }
            return 0;
        }
        else
        {
          if(node->links[word[i]-'a'])
              return dfs(word,i+1,node->links[word[i]-'a']);
            return 0;
        }
    }
   
    bool search(string word) {
        TrieNode* node =root;
        return dfs(word,0,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */