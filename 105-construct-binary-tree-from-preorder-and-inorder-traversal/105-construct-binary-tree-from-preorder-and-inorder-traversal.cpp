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
    //REMEMBER THAT FOR CREATING A UNIQUE BINARY TREE THE INORDER TRAVERSAL OF THE BT IS REQUIRED
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int &n,int is,int ie,int ps,int pe,map<int,int>& inidx)
    {
        if(ie<is||pe<ps)return NULL;
        
        TreeNode* node=new TreeNode(preorder[ps]);
        
        //no of nodes in the left subtree 
        int left=inidx[preorder[ps]]-is;
        
        //we take the left of pre as the ps<---->ps(curr)+no of values left before the val in inorder
        //we take the right of pre as the ps(curr)+no of values left before the val in inorder +1<------>end
        
        //from inorder array we know how many nodes are to the left(i(curr)) of it and how many to the right (n-(i(curr)+1))
        
        //we use this knowledge to find the start and end pointers in the preorder array
        node->left=build(preorder,inorder,n,is,inidx[preorder[ps]]-1,ps+1,ps+left,inidx);
        node->right=build(preorder,inorder,n,inidx[preorder[ps]]+1,ie,ps+left+1,pe,inidx);
        
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int n=inorder.size();
        
        //if you ever confuse whose idx to store just think which array can find no of eles to the left
        //given the idx of the root--->yechhhh its the inorder
        map<int,int>inidx;
        for(int i=0;i<n;i++)
            inidx[inorder[i]]=i;
        
        TreeNode* root=build(preorder,inorder,n,0,n-1,0,n-1,inidx);
        return root;
    }
};


//PREORDER AND POSTORDER
// TreeNode* build(vector<int> pre, vector<int> post,int prs,int pre,int pos,int poe,unordered_map<int,int> post_idx)
//     {
//         if(pre<prs||poe<pos)return NULL;
        
//         TreeNode* node=new TreeNode(pre[prs]);
        
//         if(prs==pre)return node;
        
//         int idx=post_idx[pre[prs]];
//         int left=idx-pos+1;
        
//         node->left=build(pre,post,prs+1,prs+left,pos,idx,post_idx);
//         node->right=build(pre,post,prs+left+1,pre,idx+1,poe-1,post_idx);
        
//         return node;
//     }

// TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
// {
//     int n=post.size();
//     unordered_map<int,int>post_idx;
//     for(int i=0;i<n;i++)
//     post_idx[post[i]]=i;
    
//     return build(pre,post,0,n-1,0,n-1,post_idx);
// }