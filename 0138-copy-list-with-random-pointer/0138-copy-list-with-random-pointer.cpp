/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
unordered_map<Node*,Node*>check;
class Solution {
public:
   Node*copy(Node*head)
   {
       if(head==NULL)return NULL;
        if(check.find(head)!=check.end())return check[head];
        Node*n=new Node(head->val);
        check[head]=n;
        n->next=copy(head->next);
        n->random=copy(head->random);
        return n;
   }

    Node* copyRandomList(Node* head) {
        check.clear();
        return copy(head);
       
    }
};