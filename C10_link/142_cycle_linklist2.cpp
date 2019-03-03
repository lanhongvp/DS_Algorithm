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
    ListNode *detectCycle(ListNode *head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow;
        ListNode* fast;
        ListNode* entry;
        bool ans;
        slow = dummy;
        fast = head;
        if((head==NULL)||(head->next==NULL))
            return NULL;
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
        if(!ans){
            entry = NULL;
        }else{
            //node cnt in cycle
            int nodeCnt = 1;
            ListNode* tmp1 = fast->next;
            while(tmp1!=fast){
                tmp1 = tmp1->next;
                nodeCnt++;
            }
            ListNode* p1 = head;
            ListNode* p2 = head;
            for(int i=0;i<nodeCnt;i++){
                p1 = p1->next;
            }
            while(p1!=p2){
                p1 = p1->next;
                p2 = p2->next;
            }
            entry = p1;
        }
        return entry;
    }
};