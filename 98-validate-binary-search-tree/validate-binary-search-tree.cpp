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
bool ans;
    pair<int,int> check(TreeNode*root)
    {
        if(root==NULL)return {INT_MAX,INT_MIN};
        if(root->left==NULL and root->right==NULL)return {root->val,root->val};
        if(root->right==NULL)
        {
            pair<int,int>l=check(root->left);
           if(l.second>=root->val)
           {
               ans=false;
           }
           return {min(l.first,root->val),max(l.second,root->val)};
        }
        if(root->left==NULL)
        {
            pair<int,int>r=check(root->right);
           if(r.first<=root->val)
           {
               ans=false;
           }
           return {min(r.first,root->val),max(r.second,root->val)};
        }
        pair<int,int>l=check(root->left);
        pair<int,int>r=check(root->right);
        if(root->val<=l.second or root->val>=r.first)
        {
            ans=false;
        }
        int mini=min(root->val,min(l.first,r.first));
        int maxi=max(root->val,max(r.second,l.second));
        return {mini,maxi};
    }
    bool isValidBST(TreeNode* root) {
        ans=true;
        check(root);
        return ans;
    }
};