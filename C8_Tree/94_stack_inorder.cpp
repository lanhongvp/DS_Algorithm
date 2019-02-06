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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      //1.initial
      vector<int> in_tree;
      stack<TreeNode*> s;
      TreeNode* tmp = root;
      //2.corner case
      // if(root==NULL) return NULL;
      while((tmp!=NULL)||(!s.empty())){
        if(tmp!=NULL){
          s.push(tmp);
          tmp = tmp->left;
        }else{
          // tmp = s.top();
          in_tree.push_back((s.top()->val));
          s.pop();
          tmp = s.top();
          tmp = tmp->right;
        }
      }
      return in_tree;
    }
};

int main(){
    
}