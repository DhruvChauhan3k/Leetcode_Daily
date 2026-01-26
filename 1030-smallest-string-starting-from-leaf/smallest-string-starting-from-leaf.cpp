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

 bool check(string &a,string &b){
    int i=0,j=0;
    while(i<a.size() and j<b.size()){
        if(a[i]<b[j])return true;
        if(b[j]<a[i])return false;
        i++;
        j++;
    }
    if(i==a.size())return true;
    // if(j==b.size())return false;
    return false;
 }
class Solution {
public:
string ans="";
void small(TreeNode* root, string s) {
    if(root==NULL)return;
    if(root->left==NULL and root->right==NULL)ans==""?ans=char('a'+root->val)+s:ans=min(ans,char('a'+root->val)+s);
    if(root->left!=NULL)small(root->left,char('a'+root->val)+s);
    if(root->right!=NULL)small(root->right,char('a'+root->val)+s);
}
    string smallestFromLeaf(TreeNode* root) {
        ans="";
        if(root==NULL)return "";
        small(root,"");
        return ans;
    }
};