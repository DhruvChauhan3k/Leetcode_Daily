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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt=0;
        int size=0;
        ListNode*cp=head;
        vector<ListNode*>ans;
        while(cp)
        {
            size++;
            cp=cp->next;
        }
        int all=size/k;
        int ext=size%k;
        cp=head;
        while(k)
        {
          k--;
          if(cp==NULL)
          {
            ans.push_back(NULL);
            continue;
          }
            ans.push_back(cp);
            ListNode*jk;
            if(ext)
            {
              ext--;
              int tmp=all;
              ListNode*jk=cp;
              while(tmp)
             {
                jk=jk->next;
                tmp--;
              }
              cp=jk->next;
              jk->next=NULL;
            }
            else
            {
              int tmp=all;
              if(all>0)
              {
              ListNode*jk=cp;
              tmp--;
              while(tmp)
             {
                jk=jk->next;
                tmp--;
              }
              cp=jk->next;
              jk->next=NULL;
              }
            }
        }
        return ans;
    }
};