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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool ans = false;
        if((s!=NULL) && (t!=NULL)){
            if(s->val==t->val){
                ans = hasSubtree(s,t);
            }
            if(!ans)
                ans = isSubtree(s->left,t);
            if(!ans)
                ans = isSubtree(s->right,t);
        }
        return ans;
    }
    
    bool hasSubtree(TreeNode* root1,TreeNode* root2){
        if((root2==NULL) && (root1==NULL))
            return true;
        if((root1==NULL) || (root2==NULL))
            return false;

        if(root1->val!=root2->val){
            return false;
        }
        return hasSubtree(root1->left,root2->left)&&hasSubtree(root1->right,root2->right);
    }
};