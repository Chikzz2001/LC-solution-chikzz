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
    TreeNode* construct(vector<int>& inorder, vector<int>& postorder,unordered_map<int,int>& inidx,int instart,int inend,int poststart,int postend)
    {
        if(instart>inend||poststart>postend)return NULL;
        
        TreeNode* node=new TreeNode(postorder[postend]);
        
        int i=inidx[postorder[postend]];
        int left=i-instart;
        
        node->left=construct(inorder,postorder,inidx,instart,i-1,poststart,poststart+left-1);
        node->right=construct(inorder,postorder,inidx,i+1,inend,poststart+left,postend-1);
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>inidx;
        int n=inorder.size();
        
        for(int i=0;i<n;i++)
            inidx[inorder[i]]=i;
        
        return construct(inorder,postorder,inidx,0,n-1,0,n-1);
    }
};