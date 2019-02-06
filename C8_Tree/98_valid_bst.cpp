/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //bool result=true;
   bool isValidBST(TreeNode* root) {
        //1.initial
        bool result=true;
        queue<TreeNode*> q;
        //2.corner case
        if(root==NULL) return true;
        //3.main pro
        q.push(root);
      
        while(!q.empty()){
          TreeNode* tmp = q.front();
          q.pop();
          TreeNode* L = tmp->left;
          if(L){
            if(L->val>=tmp->val){
              result = false;
              break;
            }
            q.push(L);
          }
          TreeNode* R = tmp->right;
          if(R) {
            if(R->val<=tmp->val){
              result = false;
              break;
            }
            q.push(R);
          }         
        }
      return result;
    }

    TreeNode* create_bst(vector<int> data){
        TreeNode* root = NULL;
        for(int i=0;i<data.size();i++){
            insert(root,data[i]);
            // cout<<"xi";
        }
        return root;
    }
    void insert(TreeNode* &r,int x){
        if(r==NULL){
            r = new TreeNode(x);
            return;
        }
        if(r->val==x) return;
        else if(r->val<x) insert(r->right,x);
        else insert(r->left,x);
    }

    void preorder(TreeNode* r){
        // cout<<"haha";
        if(r==NULL) return;
        cout<<r->val<<" ";
        preorder(r->left);
        preorder(r->right);
    }
};

int main(){
    vector<int> data;
    data = {10,5,15,6,20};
    TreeNode* root = Solution().create_bst(data);
    bool result = Solution().isValidBST(root);
    cout<<result;
}