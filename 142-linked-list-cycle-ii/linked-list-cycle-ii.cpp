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
    ListNode *detectCycle(ListNode *head) {
        ListNode*st=head,*slow=head,*fast=head;
        int check=0;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                check=1;
                break;
            }
        }
        if(check==0)return NULL;
        while(slow!=st)
        {
            st=st->next;
            slow=slow->next;
        }
        return st;
    }
};