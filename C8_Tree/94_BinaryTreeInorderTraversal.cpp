#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
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
    
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
      stack<TreeNode* > s;
      s.push(root);
      TreeNode* top_node = s.top();
      
      while(!s.empty()){
          cout<<"xi";
        if(top_node->left){
          s.push(top_node->left);
          top_node = top_node->left;    
        }else{
          TreeNode* tmp = s.top();
          top_node = top_node->right;          
          s.pop();
          ans.push_back(tmp->val);
        //   top_node = s.top();
        }
      }
      return ans;
    }
};

int main(){
    vector<int> data;
    vector<int> ans;
    data = {5,3,7,4,2,8,6};
    TreeNode* root = Solution().create_bst(data);
    ans = Solution().inorderTraversal(root);
    cout<<"ans "<<ans[0];
    // Solution().preorder(root);
}