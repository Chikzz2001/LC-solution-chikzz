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
public:
    
//      void inorder(TreeNode* root,vector<int>& v)
//     {
//         if(root==NULL)return;
        
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
    vector<int> inorderTraversal(TreeNode* root) {
        //   vector<int>v;
        // inorder(root,v);
        // return v;
        
//         vector<int>inorder;
//         //MORRIS TRAVERSAL
//         if(!root)return inorder;
//         TreeNode* curr=root;
//         while(curr)
//         {
//             if(!curr->left)
//             {
//                 inorder.push_back(curr->val);
//                 curr=curr->right;
//             }
//             else
//             {
//                 TreeNode* pre=curr->left;
//                 while(pre->right && pre->right!=curr)pre=pre->right;
                
//                 if(!pre->right)
//                 {
//                     pre->right=curr;
//                     curr=curr->left;
//                 }
//                 else
//                 {
//                     pre->right=NULL;
//                     inorder.push_back(curr->val);
//                     curr=curr->right;
//                 }
//             }
//         }
//         return inorder;
        
        vector<TreeNode*>stack;
        vector<int>res;  
    
         while(root||!stack.empty())
         {
             //go complete left ---->  push the top node in the stack in the resultant vector --->  root->root->right
             while(root)
             {
                 stack.push_back(root);
                 root=root->left;
             }
             
             root=stack.back();
             stack.pop_back();
             
             res.push_back(root->val);
             root=root->right;
         }
        return res;
    }
};