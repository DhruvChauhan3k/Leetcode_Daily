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
int level;
    void  check(TreeNode*root,int lvl,unordered_map<int,int>&m)
    {
        if(root==NULL)return;
        level=max(level,lvl);
        m[lvl]+=root->val;
        check(root->left,lvl+1,m);
        check(root->right,lvl+1,m);
    }
    int maxLevelSum(TreeNode* root) {
        level=0;
        int maxi=INT_MIN;
        int ans=-1;
        unordered_map<int,int>m;
        check(root,1,m);
        for(int i=1;i<=level;i++)
        {
            if(m[i]>maxi)
            {
                maxi=m[i];
                ans=i;
            }
        }
        return ans;
    }
};