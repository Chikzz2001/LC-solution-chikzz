/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
//     int search(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode* &ans)
//     {
//         if(!root||ans!= NULL)return 0;
        
//         int sl=search(root->left,p,q,ans);
//         int sr=search(root->right,p,q,ans);
        
//         if((root==p||root==q)&&(sl+sr==1))ans=root;
//         if(sl==1&&sr==1)ans=root;
        
//         if(root==p||root==q)return 1;
//         return sl+sr;        
//     }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        
        // TreeNode* ans=NULL;
        // int a=search(root,p,q,ans);
        // return ans;
       if(!root)return NULL;
    
//         THE SUBTREE FROM WHERE WE DO NOT GET ANY OF THE REQUIRED NODES RETURN NULL
        
//         CASE:1 IF WE HAVE BOTH VALUE IN THE EITHER OF THE SUBTREE
//         (here we consider that both the nodes are at left subtree)
//         --->WE WILL GET THE MATCHING NODE THAT WE ENCOUNTER FIRST FROM THE LEFT SUBTREE AND WE WILL 
//         GET A NULL FROM THE RIGHT SUBTREE SO WHEN WE SEE EITHER OF THE SUBTREES RETURNING NULL
//         WE RETURN THE RESULT FROM THE OTHER SUBTREE
        
//         CASE 2:WHEN BOTH THE SUBTREES CONTAIN ONE NODE EACH
//         WE WILL GET THE ENCOUNTERED NODE FROM BOTH THE TREES AND AS EITHER OF THEM IS NOT
//         NULL SO WE RETURN THE ROOT AS THE ANSWER
        
//         CASE:3 
//         IF BOTH THE NODES ARE NOT PRESENT(ALTHOUGH THIS IS NOT INCLUDED IN THE TCS AS P AND Q
//         BOTH ARE NODES OF THE TREE GIVEN TO US)
//         STILL THIS SOLUTION WORKS IN THIS CASE AS WE GET NULL FROM BOTH THE SUBTREES
//         WE RETURN NULL AS THE FINAL RESULT
        
//         CASE 4:
//         IF ONE OF THE NODE IS NOT PRESENT
//         THIS SOLUTION FAILS DURING SUCH A CASE BUT WE SHOULD NOT TALK ABOUT THIS CASE AS 
//         WE ARE SAID THAT THE GIVEN P AND Q ARE PRESENT IN THE GIVEN TREE
        
        if(root==p||root==q)return root;
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(!left)return right;
        if(!right)return left;
        
        return root;
    }
};