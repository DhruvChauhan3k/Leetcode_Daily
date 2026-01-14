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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*temp=list1;
        
        while(a>1){
            list1=list1->next;
            a--;
        }
        ListNode*temp2=temp;
        while(b){
            temp2=temp2->next;
            b--;
        }
                
        list1->next=list2;
        while(list2->next!=NULL)list2=list2->next;
        ListNode*x=temp2;
        list2->next=x->next;
        temp2->next=NULL;
        return temp;
    }
};