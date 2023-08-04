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
     TreeNode*check(TreeNode*&root)
     {
        if(root==NULL)return root;
        if(root->left==NULL and root->right==NULL)return root;
        if(root->right==NULL)
        {
            TreeNode*l=check(root->left);
            root->right=root->left;
            root->left=NULL;
            return l;
        }
        if(root->left==NULL)
        {
            TreeNode*r=check(root->right);
            return r;
        }
        TreeNode*l=check(root->left);
        TreeNode*r=check(root->right);
        l->right=root->right;
        root->right=root->left;
        root->left=NULL;
        return r;
     }
    void flatten(TreeNode* root) {
       check(root);
    }
};