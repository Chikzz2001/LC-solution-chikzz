class TrieNode
{
    TrieNode *links[26];
    bool flag=0;
    public:
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    TrieNode* getNode(char ch)
    {
        return links[ch-'a'];
    }
    
    void putNode(char ch,TrieNode* node)
    {
        links[ch-'a']=node;
    }
    
    void setEnd()
    {
        flag=1;
    }
    
    bool isEnd()
    {
        return flag;
    }
};

class Trie 
{
    TrieNode* root;
public:
    Trie() 
    {
        root=new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode* node=root;
        
        for(auto &ch:word)
        {
            if(node->containsKey(ch))
            {
                node=node->getNode(ch);
            }
            else
            {
                node->putNode(ch,new TrieNode());
                node=node->getNode(ch);
            }
        }
        
        node->setEnd();
    }
    
    bool search(string word) 
    {
        TrieNode* node=root;
        for(auto &ch:word)
        {
            if(!node->containsKey(ch))
                return 0;
            
            node=node->getNode(ch);
        }
        
        return node->isEnd();
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* node=root;
        for(auto &ch:prefix)
        {
            if(!node->containsKey(ch))
                return 0;
            
            node=node->getNode(ch);
        }
        
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */