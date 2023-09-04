/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL or head->next==NULL)return false;
        ListNode*nxt=head->next;
        while(nxt and nxt->next)
        {
            if(head==nxt)return true;
            nxt=nxt->next->next;
            head=head->next;
        }
        return false;
    }
};