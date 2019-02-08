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
#include<stack>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        vector<vector<int>> result;
        vector<int> tmp;
        q.push(root);
        tmp.push_back(root->val);
        int depth = 0;
        cout<<"he";
        result.push_back(tmp);
        tmp.clear();
        cout<<"haha";
        while(!q.empty()){
            cout<<"xi";
          TreeNode* top_node = q.front();
          q.pop();
          depth++;
          TreeNode* left_node;
          left_node = top_node->left;          
          TreeNode* right_node;
          right_node = top_node->right;
          if(left_node){
            q.push(left_node); 
            tmp.push_back(left_node->val);
          }
          if(right_node){
            q.push(right_node); 
            tmp.push_back(right_node->val);
          }
          result.push_back(tmp);
          tmp.clear();
        }
      return result;
    }

    TreeNode* create_bst(vector<int> data){
        TreeNode* root = NULL;
        for(unsigned int i=0;i<data.size();i++){
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
};

int main(){
    vector<int> data;
    vector<vector<int>> result;
    data = {3,9,20,15,7};
    TreeNode* root = Solution().create_bst(data);
    result = Solution().levelOrder(root);
    cout<<result.size();
    
}