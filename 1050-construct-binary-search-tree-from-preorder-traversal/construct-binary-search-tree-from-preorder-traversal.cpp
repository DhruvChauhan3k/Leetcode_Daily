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
int i=0;
    void create(TreeNode*&root,vector<int>&pre,int check)
    {
        if(i>=pre.size() or pre[i]>=check)return;
        root=new TreeNode(pre[i]);
        i++;
        create(root->left,pre,root->val);
        create(root->right,pre,check);
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode*root;
        create(root,pre,INT_MAX);
        return root;
    }
};