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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head;
        ListNode* before = dummy;
        int dup = 0;
        if(head==NULL)
            return head;
        while(cur){
            while((cur->next!=NULL)&&(cur->next->val==cur->val)){
                cur->next = cur->next->next;
                dup = 1;
            }
            if(dup==1){
                dup = 0;
                before->next = cur->next;
            }else if(dup==0){
                before = before->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};