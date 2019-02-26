/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next==NULL){
            return head;
        }else{
            ListNode* tmp = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return tmp;
        }
    }

    ListNode* insert(int x){
        ListNode* cur;
        cur = new ListNode(x);
        return cur;
    }
};

//iteration
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* next = cur->next;
            if(next==NULL){
                newHead = cur;
            }
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return newHead;
    }
};

int main(){
    vector<int> v;
    v = {1,2,3};
    ListNode* head = new ListNode(0);
    ListNode* cur;
    ListNode* tail;
    cur = head;
    for(unsigned i=0;i<v.size();i++){
        cur->next = Solution().insert(v[i]);
        cur = cur->next;
    }
    tail = Solution().reverseList(head->next);
    cout<<"val "<<tail->val;
}