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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head->next;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        if(head==NULL||head->next==NULL){
            return head;
        }
        while(cur){
            if(cur->val!=head->val){
                cur = cur->next;
                head = head->next;
            }else{
                cur = cur->next;
                head = head->next;
                head->next = cur;
            }
        }
        return head;
    }
};

class Solution1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        
        while(cur!=NULL){
            if(cur->next==NULL){
                return head;
            }
            if(cur->next->val==cur->val){
                //会修改head->next
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};