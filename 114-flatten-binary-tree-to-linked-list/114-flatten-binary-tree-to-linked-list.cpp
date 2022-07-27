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
TreeNode* prev=NULL;
public:
    void flatten(TreeNode* root) {
       
        if(!root)return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right=prev;
        root->left=NULL;
        
        prev=root;
        
//         if(!root)return;
//         stack<TreeNode*>st;
//         st.push(root);
        
//         //what will be the next pointer to the current node?
//         //obviously the one that comes left of the current node so we need to keep
//         //the node at the left on the top of the stack so as to form the link
//         //so we need to push the right node first in the stack and then the left node.
        
//         while(!st.empty())
//         {
            
//             TreeNode* curr=st.top();st.pop();
            
//             if(curr->right)st.push(curr->right);
            
//             if(curr->left)st.push(curr->left);
            
//             if(!st.empty())curr->right=st.top();
//             curr->left=NULL;
            
//         }
    }
};