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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        int cnt = 1;
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = dummy;
        while((cnt<=n)){
            //cout<<cur->val<<" ";
            cur = cur->next;
            cnt++;
        }
        while(cur){
            //cout<<"cur "<<cur->val<<" ";
            //cout<<"pre "<<pre->val<<" ";
            if((cur->next)==NULL){
                pre->next = pre->next->next;
                break;
            }else{
                cur = cur->next;
                pre = pre->next;
            }
            cout<<endl;
        }
        return dummy->next;
    }
};