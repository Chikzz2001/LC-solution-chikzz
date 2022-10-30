```
class Solution {
map<int,set<int>,greater<int>>m;
map<int,int>lc,rc;
map<int,int>h;
// map<int,TreeNode*>nodes;
void dfs(TreeNode* root,int height)
{
if(!root)return;
h[root->val]=height;
m[height].insert(root->val);
//nodes[root->val]=root;
if(root->left){lc[root->val]=root->left->val;dfs(root->left,height+1);}
if(root->right){rc[root->val]=root->right->val;dfs(root->right,height+1);}
}
void removenodes(int root)
{
if(!h.count(root))return;
m[h[root]].erase(root);
if(!m[h[root]].size())m.erase(h[root]);
h.erase(root);
if(lc.count(root))removenodes(lc[root]);
if(rc.count(root))removenodes(rc[root]);
}
public:
vector<int> treeQueries(TreeNode* root, vector<int>& queries)
{
dfs(root,0);
vector<int>res;
for(auto &q:queries)
{
removenodes(q);
res.push_back((*m.begin()).first);
}
return res;
}
};
```