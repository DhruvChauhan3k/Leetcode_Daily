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
    int treeHeight(TreeNode*root){
        if(root==NULL)return 0;
        return 1+max(treeHeight(root->left),treeHeight(root->right));
    }
    bool deepLCA(TreeNode*&root,TreeNode*&ans,int deepest){
        if(root==NULL)return false;
        if(deepest==0){
            ans=root;
            return true;
        }
        bool l=deepLCA(root->left,ans,deepest-1);
        bool r=deepLCA(root->right,ans,deepest-1);
        if(l==true and r==true){
            ans=root;
            return true;
        }
        if(l==true || r==true)return true;
        return false;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int deepest=treeHeight(root)-1;
        TreeNode*ans=NULL;
        deepLCA(root,ans,deepest);
        return ans;
    }
};