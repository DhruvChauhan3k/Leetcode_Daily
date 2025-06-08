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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        unordered_map<Node*,Node*>m;
        Node*copy=new Node(head->val);
        Node*head2=head;
        m[head]=copy;
        head=head->next;
        Node*tmp=copy;
        while(head!=NULL){
            tmp->next=new Node(head->val);
            tmp=tmp->next;
            m[head]=tmp;
            head=head->next;
        }
        tmp=copy;
        while(head2!=NULL){
             tmp->random=m[head2->random];
             head2=head2->next;
             tmp=tmp->next;
        }
        return copy;
    }
};