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
    
    int height(TreeNode* root)
    {
        if(!root)return 0;
        return 1+height(root->left);
    }
    
    void missing(TreeNode* root,int h,bool &f,int &miss)
    {
        if(h==1){root?f=1:miss++;}
        if(!root||f)return;
        missing(root->right,h-1,f,miss);
        missing(root->left,h-1,f,miss);
    }
    
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        
        bool f=0;
        int h=height(root);
        
        int miss=0;
        missing(root,h,f,miss);
        
        int ans=(1<<h)-1;
        
        return ans-miss;
    }
};