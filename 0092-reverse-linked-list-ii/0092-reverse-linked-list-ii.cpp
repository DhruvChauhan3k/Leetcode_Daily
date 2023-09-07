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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>v;
        ListNode*tmp=head;
        while(tmp)
        {
            v.push_back(tmp->val);
            tmp=tmp->next;
        }
        reverse(v.begin()+left-1,v.begin()+right);
        ListNode*ne=new ListNode(v[0]);
        ListNode*ans=ne;
        int i=1;
        while(i<v.size())
        {
            ne->next=new ListNode(v[i]);
            ne=ne->next;
            i++;
        }
        return ans;
    }
};