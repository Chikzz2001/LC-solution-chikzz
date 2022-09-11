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
    int res=0;
    //for every node we need to return the left max alternate path and right max alternate path
    void dfs(TreeNode* root,int l,int r)
    {
        if(!root)return;
        
        if(root->left)
        {
            res=max(res,1+l);
            dfs(root->left,0,1+l);
        }
        
        if(root->right)
        {
            res=max(res,1+r);
            dfs(root->right,1+r,0);
        }
    }
public:
    int longestZigZag(TreeNode* root) 
    {
        dfs(root,0,0);
        return res;
    }
};