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
void check(ListNode*l1,ListNode*l2,ListNode*&ans,int now)
{
    if(l1==NULL and l2==NULL)
    {
        if(now>0)
        {
            ans=new ListNode(now);
        }
        return;
    }
    else if(l2==NULL)
    {
    ans=new ListNode((l1->val+now)%10);
    check(l1->next,l2,ans->next,(l1->val+now)/10);  
    return;  
    }
    else if(l1==NULL)
    {
    ans=new ListNode((l2->val+now)%10);
    check(l1,l2->next,ans->next,(l2->val+now)/10);  
    return;  
    }
    ans=new ListNode((l1->val+l2->val+now)%10);
    check(l1->next,l2->next,ans->next,(l1->val+l2->val+now)/10);
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ans;
        check(l1,l2,ans,0);
        return ans;
    }
};