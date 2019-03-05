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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        if(leftDepth>rightDepth){
            leftDepth++;
        }else{
            rightDepth++;
        }
        return leftDepth>rightDepth?leftDepth:rightDepth;
    }
};