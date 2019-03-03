/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
            return ans;
        post(root,ans);
        return ans;
    }
    void post(TreeNode* root,vector<int>& ans){
        if(root==NULL)
            return;
        if(root->left){
            ans = postorderTraversal(root->left);
        }
        if(root->right){
            ans = postorderTraversal(root->right);
        }
        //if((root->left==NULL)&&(root->right==NULL)){
        ans.push_back(root->val);
        //}   
    }
};