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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        vector<vector<int>>res;
        while(q.size())
        {
            int size=q.size();
            vector<int>temp;
            while(size--)
            {
                TreeNode* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            
            if(level&1)
            {
               vector<int>temp2;
                int n=temp.size();
                while(n)
                {
                    int x=temp[--n];
                    temp2.push_back(x);
                }
                res.push_back(temp2);
            }
            else
                res.push_back(temp);
            
            level++;
        }
        return res;
    }
};