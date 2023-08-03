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
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        long long int ans=0;
        while(!q.empty())
        {
            long long int sub=q.front().second;
           long long int first=0,last=0;
           long long int ni=q.size();
            for(int i=0;i<ni;i++)
            {
                
                long long int now=q.front().second-sub;
                TreeNode*n=q.front().first;
                q.pop();
                if(n->left!=NULL)
                {
                    q.push({n->left,now*2+1});
                }
                if(n->right!=NULL)
                {
                    q.push({n->right,now*2+2});
                }
                if(i==0)
                {
                    first=now;
                }
                if(i==ni-1)
                {
                    last=now;
                }
                
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};