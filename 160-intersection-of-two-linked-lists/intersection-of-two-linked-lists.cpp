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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        unordered_map<ListNode*,int>m;
        ListNode*ans;
        while(a!=NULL)
        {
            m[a]++;
            a=a->next;
        }
        while(b!=NULL)
        {
            if(m.find(b)!=m.end())return b;
            b=b->next;
        }
        return NULL;
    }
};