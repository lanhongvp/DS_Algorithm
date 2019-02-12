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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1==NULL && l2==NULL) return nullptr;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 && l2){
          if(l1->val < l2->val){
              cur->next = new ListNode(l1->val);
              if(l1) l1 = l1->next;
              cur = cur->next;
          }else{
              cur->next = new ListNode(l2->val);
              if(l2) l2 = l2->next;
              cur = cur->next;
          }
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        return head->next;
    }
};