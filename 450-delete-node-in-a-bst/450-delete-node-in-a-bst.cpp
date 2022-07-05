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
    TreeNode* getSuccessor(TreeNode* root)
    {
        root=root->right;
        while(root->left)
        {
            root=root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)return NULL;
        if(root->val<key)
            root->right=deleteNode(root->right,key);
        else if(root->val>key)
            root->left=deleteNode(root->left,key);
        else
        {
            if(!root->left)
            {
                TreeNode* right=root->right;
                delete root;
                return right;
            }
            else if(!root->right)
            {
                TreeNode* left=root->left;
                delete root;
                return left;
            }
            else
            {
                TreeNode* succ=getSuccessor(root);
                root->val=succ->val;
                root->right=deleteNode(root->right,succ->val);
                return root;
            }
        }
        return root;
    }
};