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
    unordered_map<int,int>m;
    TreeNode* construct(vector<int>& Pre,vector<int>& Post,int prs,int pre,int pos,int poe)
    {
        if(prs>pre||pos>poe)
            return NULL;
        
        if(prs==pre)return new TreeNode(Pre[prs]);
        TreeNode* root=new TreeNode(Pre[prs]);
        int left=m[Pre[prs+1]]-pos;
        TreeNode* l=construct(Pre,Post,prs+1,prs+left+1,pos,pos+left);
        TreeNode* r=construct(Pre,Post,prs+left+2,pre,pos+left+1,poe-1);
        root->left=l,root->right=r;
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        int n=post.size();
        for(int i=0;i<n;i++)
            m[post[i]]=i;
        
        return construct(pre,post,0,n-1,0,n-1);
    }
};

/*
pre:[1,2,4,5,3,6,7]
post:[4,5,2,6,7,3,1]

l=pre:[2,4,5],post:[4,5,2]--->
r=pre:[3,6,7],post:[6,7,3]
*/