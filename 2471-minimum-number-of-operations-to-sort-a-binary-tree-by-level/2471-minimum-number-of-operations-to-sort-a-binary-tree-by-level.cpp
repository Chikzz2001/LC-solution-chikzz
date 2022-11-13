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
   class DSU
{
public:
    map<int,int>par,size;
    DSU(vector<int>& v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            par[v[i]] = v[i];
            size[v[i]] = 1;
        }
    }

    int find(int x)
    {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }

    bool is_joined(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return 1;

        if (size[pa] <= size[pb])
        {
            par[pa] = pb;
            size[pb] += size[pa];
        }
        else
        {
            par[pb] = pa;
            size[pa] += size[pb];
        }

        return 0;
    }
};
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>Q;
        Q.push(root);
        int res=0;
        while(!Q.empty())
        {
            vector<int>v;
            int size=Q.size();
            while(size--)
            {
                auto curr=Q.front();Q.pop();
                if(curr->left){Q.push(curr->left);v.push_back(curr->left->val);}
                if(curr->right){Q.push(curr->right);v.push_back(curr->right->val);}
            }
            DSU dsu(v);
            vector<int>vv=v;
            sort(vv.begin(),vv.end());
            for(int i=0;i<v.size();i++)
                dsu.is_joined(v[i],vv[i]);
            set<int>parents;
            for(int i=0;i<v.size();i++)parents.insert(dsu.find(v[i]));
            for(auto &x:parents)res+=(dsu.size[x]-1);
        }
        return res; 
    }
};