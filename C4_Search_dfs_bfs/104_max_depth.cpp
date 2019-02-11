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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int L=0;
    int R=0;
    int maxDepth(TreeNode* root) {
       int ans;
       if(root==NULL) return 0;
        ans = dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* t){
        if(t)
            cout<<t->val<<" "<<endl;
        if(t==NULL) 
            return 0;
        // if(t->left){
            L = dfs(t->left)+1;
            cout<<"L "<<L<<" ";   
        // }
        // if(t->right){
            R = dfs(t->right)+1;
            cout<<"R "<<R<<" ";
            cout<<"ha"<<endl;     
        // }
        if(L>R) return L;
        else return R;
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
    vector<int> data = {5,4,7};
    root = Solution().create_bst(data);
    int ans = Solution().maxDepth(root);
    cout <<"ans "<<ans;
}