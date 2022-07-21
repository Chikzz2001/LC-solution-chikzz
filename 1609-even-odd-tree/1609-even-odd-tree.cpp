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
    vector<int>store;
    int height(TreeNode* root)
    {
        return root?1+max(height(root->left),height(root->right)):0;
    }
    
    bool isEvenOdd(TreeNode* root,int level)
    {
        if(!root)return 1;
        if(level&1&&root->val>=store[level])return 0;
        if(!(level&1)&&root->val<=store[level])return 0;
        if(!((root->val&1)^(level&1)))return 0;
        store[level]=root->val;
        return isEvenOdd(root->left,level+1)&isEvenOdd(root->right,level+1);
    }
public:
    bool isEvenOddTree(TreeNode* root) 
    {
        int h=height(root);
        store=vector<int>(h);
        for(int i=0;i<h;i++)
            store[i]=i&1?1e6+1:0;
        
        return isEvenOdd(root,0);
    }
};