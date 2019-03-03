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
    bool hasCycle(ListNode *head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow;
        ListNode* fast;
        bool ans;
        slow = dummy;
        fast = head;
        if((head==NULL)||(head->next==NULL))
            return false;
        while((slow!=fast)&&(fast!=NULL)){
            slow = slow->next;
            fast = fast->next;  
            if(fast!=NULL)
                fast = fast->next;
        }
        if((fast==NULL) && (slow!=fast)){
            ans = false;
        }else if((fast!=NULL) && (slow==fast)){
            ans = true;
        }
        return ans;
    }
};