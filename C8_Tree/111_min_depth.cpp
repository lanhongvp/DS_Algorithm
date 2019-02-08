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
    int left_d=1;
    int right_d=1;
    int minDepth(TreeNode* root) {
      if(root==NULL) return 0;
      if(root->left==NULL && root->right==NULL) return 1;
      left_d += minDepth(root->left);
      right_d += minDepth(root->right);
      return min(left_d,right_d);
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
};

int main(){
    TreeNode* root;
    vector<int> data = {5,4,7,2,3,6,8};
    root = Solution().create_bst(data);
    int ans = Solution().minDepth(root);
    cout <<"ans "<<ans;
}