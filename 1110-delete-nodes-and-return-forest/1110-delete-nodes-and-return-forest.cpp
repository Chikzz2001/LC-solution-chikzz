/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    set<int>del;
    vector<TreeNode*>res;
    TreeNode* helper(TreeNode* root)
    {
        if(!root)return NULL;
        TreeNode* l=helper(root->left);
        TreeNode* r=helper(root->right);
        root->left=l,root->right=r;
        if(del.count(root->val))
        {
            if(l)
            res.push_back(l);
            if(r)
            res.push_back(r);
            return NULL;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto &d:to_delete)
            del.insert(d);
        TreeNode* h=helper(root);
        if(h)
            res.push_back(h);
        return res;
    }
};