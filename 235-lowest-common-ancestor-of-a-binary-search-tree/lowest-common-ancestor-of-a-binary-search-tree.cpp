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
public:
    TreeNode* lowestCommonAncestor(TreeNode* &root, TreeNode* &p, TreeNode* &q) {
        if(!root)return NULL;
        TreeNode*a=lowestCommonAncestor(root->left,p,q);
        TreeNode*b=lowestCommonAncestor(root->right,p,q);
        if(a and b)return root;
        if(root==p or root==q)return root;
        if(a)return a;
        if(b)return b; 
          return NULL;
    }
};