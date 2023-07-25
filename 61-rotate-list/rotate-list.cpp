/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL)return head;
        ListNode*h=head;
        int len=0;
        ListNode*prev;
        while(head!=NULL)
        {
            prev=head;
            head=head->next;
            len++;
        }
        prev->next=h;
        head=h;
        k=k%len;
        k=len-k-1;
        while(k>0)
        {
            head=head->next;
            k--;
        }
        h=head->next;
        head->next=NULL;
        return h;
    }
};