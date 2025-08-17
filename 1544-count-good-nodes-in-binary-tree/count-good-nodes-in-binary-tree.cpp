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
    int check(TreeNode*&root,int max){
        if(root==NULL)return 0;
        if(root->val>=max){
            return 1+check(root->left,root->val)+check(root->right,root->val);
        }
        return check(root->left,max)+check(root->right,max);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;
        return check(root,root->val);
    }
};