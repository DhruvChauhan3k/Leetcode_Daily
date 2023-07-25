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
    bool check(ListNode*a,ListNode*&b)
    {
        if(a==NULL)
        {
            return true;
        }
        bool j=check(a->next,b);
        if(b->val==a->val)
        {
            b=b->next;
            return j;
        }
        b=b->next;
        return false;
    }
    bool isPalindrome(ListNode* head) {
        return check(head,head);
    }
};