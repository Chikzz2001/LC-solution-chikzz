class Solution {
    class TrieNode
    {
        public:
        TrieNode* links[26];
        bool f=0;
    };
    
    class Trie
    {
        public:
        TrieNode* root;
        Trie()
        {
            root=new TrieNode();
        }
        
        void insert(string &s)
        {
            TrieNode* node=root;
            
            for(auto &ch:s)
            {
                if(!node->links[ch-'a'])
                    node->links[ch-'a']=new TrieNode();
                
                node=node->links[ch-'a'];
            }
            node->f=1;
        }
    };
    
    int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& board,int i,int j,string word,TrieNode* root,unordered_set<string>& s)
    { 
        if(root->links[board[i][j]-'a'])
        {
            word+=board[i][j];
            root=root->links[board[i][j]-'a'];
            
             if(root->f)
            {
                s.insert(word);
            }
            
            char temp=board[i][j];
            board[i][j]='#';
            for(int k=0;k<4;k++)
            {
                int ni=i+dir[k][0];
                int nj=j+dir[k][1];
            
                if(ni>=0&&nj>=0&&ni<board.size()&&nj<board[0].size()&&board[ni][nj]!='#')
                dfs(board,ni,nj,word,root,s);
            }
        
            board[i][j]=temp;
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        Trie trie;
        
        for(auto &w:words)
            trie.insert(w);
        
        TrieNode* root=trie.root;
        
        unordered_set<string>s;
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                dfs(board,i,j,"",root,s);
        
        vector<string>res;
        
        for(auto &x:s)
            res.push_back(x);
        
        return res;
    }
};