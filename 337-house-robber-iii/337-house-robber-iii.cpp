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
    struct node
    {
        int take,non_take;
        node(int _take,int _non_take)
        {
            take=_take;
            non_take=_non_take;
        }
    };
    
    node max_stolen(TreeNode* root)
    {
        if(!root)
            return {0,0};
        
        int take=0,non_take=0;
        
        auto [takeL,non_takeL]=max_stolen(root->left);
        auto [takeR,non_takeR]=max_stolen(root->right);
        //when u are taking the root in ans u r constrained by the fact that u can't choose either 
        //root->left or root->right..u hv to steal from beyond those nodes
        take=root->val+non_takeL+non_takeR;
        //when u are not taking root..u r not bound to take only max values from left and right only..if
        //the nodes beyond that give u greater values u will obviously take it.
        non_take=max(non_takeL,takeL)+max(non_takeR,takeR);
        
        return {take,non_take};
    }
public:
    int rob(TreeNode* root) 
    {
        auto [take,non_take]=max_stolen(root);
        return max(take,non_take);
    }
};