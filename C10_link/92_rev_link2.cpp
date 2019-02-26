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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        if(m==n){
            return head;
        }
        for(int i=1;i<m;i++){
            pre = cur;
            cur = cur->next;
        }
        ListNode* reverse_before = pre;
        ListNode* reverse_start = cur;
        ListNode* next_node;
        pre = cur;
        cur = cur->next;
        for(int i=0;i<n-m;i++){
            next_node = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next_node;
        }
        reverse_before->next = pre;//思考链表的内存模型
        reverse_start->next = next_node;
        return dummy->next;
    }
};