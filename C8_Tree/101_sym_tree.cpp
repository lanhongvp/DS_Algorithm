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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        bool ans;
        ans = isSametree(root->left,root->right);
        return ans;
    }
    
    bool isSametree(TreeNode* r1,TreeNode* r2){
        if((r1==NULL) && (r2==NULL))
            return true;
        if((r1==NULL) || (r2==NULL))
            return false;
        if(r1->val!=r2->val)
            return false;
        return isSametree(r1->left,r2->right)&&isSametree(r1->right,r2->left);
        
    }
};