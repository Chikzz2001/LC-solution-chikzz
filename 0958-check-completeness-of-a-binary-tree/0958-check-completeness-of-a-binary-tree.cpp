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
        return !root?0:1+max(height(root->left),height(root->right));
    }
public:
    bool isCompleteTree(TreeNode* root) 
    {
        //once there appears a node which do not have both children set f=1 i.e.,after that
        //if we get any child we return false.
        
        //if any node other than the level just before the last level has less than 2 child
        //return false.
        
        
        bool f=0;
        queue<TreeNode*>q;
        
        q.push(root);
        
        int h=height(root);
        
        while(!q.empty())
        {
            if(!--h)break;
            int size=q.size();
            while(size--)
            {
                 auto curr=q.front();q.pop();
                
                if(f&&!(!curr->left&&!curr->right))return 0;
                if(curr->left&&curr->right)
                {
                    q.push(curr->left);
                    q.push(curr->right);
                }
                else
                {
                    if(h>1)return 0;
                    f=1;
                    if(curr->right)return 0;
                }
            }
        }
        return 1;
    }
};