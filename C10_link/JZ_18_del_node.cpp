#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

class LinkList {
public:
    ListNode* insertNode(vector<int> nums){
        ListNode* dummy = new ListNode(0);
        ListNode* head = new ListNode(nums[0]);
        int n = nums.size();
        dummy->next = head;
        for(int i=1;i<n;i++){
            head->next = new ListNode(nums[i]);
            //cout<<"val "<<head->val;
            head = head->next;
        }
        return dummy->next;
    }

    ListNode* deleteNode(ListNode* head,ListNode* delNode){
        
    }
};

int main(){
    vector<int> nums;
    ListNode* head;
    nums = {1,2,3,4,5};
    head = LinkList().insertNode(nums);
    while(head!=NULL){
        cout<<head->val<<" ";
        //cout<<head;
        //cout<<"haha";
        head = head->next;
    }
}