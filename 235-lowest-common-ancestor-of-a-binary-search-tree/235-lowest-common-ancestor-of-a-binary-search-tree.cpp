/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)return NULL;
        if(p->val<=root->val&&q->val>=root->val)
            return root;
        else if(p->val<=root->val&&q->val<=root->val)
            return lca(root->left,p,q);
        return lca(root->right,p,q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
              if(!root)return NULL;
        if(p->val>q->val)swap(p,q);
        return lca(root,p,q);
    }
};