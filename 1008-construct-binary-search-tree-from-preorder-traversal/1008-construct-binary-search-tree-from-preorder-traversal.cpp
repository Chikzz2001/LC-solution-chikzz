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
    int idx=0;
    TreeNode* construct(vector<int>& preorder,int minn,int maxx)
    {
        TreeNode* root=NULL;
        if(idx>=preorder.size())return root;
        
        if(preorder[idx]>minn&&preorder[idx]<maxx)
        {
            root=new TreeNode(preorder[idx]);
            idx++;
            root->left=construct(preorder,minn,root->val);
            root->right=construct(preorder,root->val,maxx);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        if(!preorder.size())return NULL;
        return construct(preorder,-1e5,1e5);
    }
};