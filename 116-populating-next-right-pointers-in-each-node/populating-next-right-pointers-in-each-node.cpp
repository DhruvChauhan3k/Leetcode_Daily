/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
void check(Node*root,unordered_map<int,Node*>&m,int lvl)
{
        if(root==NULL)return;
        if(m.find(lvl)!=m.end())
        {
            m[lvl]->next=root;
            m[lvl]=root;
        }
        m[lvl]=root;
        check(root->left,m,lvl+1);
        check(root->right,m,lvl+1);
}
    Node* connect(Node* root) {
        unordered_map<int,Node*>m;
        check(root,m,0);
        return root;
    }
};