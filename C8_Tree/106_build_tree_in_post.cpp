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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode* createTree(vector<int>& in,int s1,int e1,vector<int>& post,int s2,int e2){
        if(e1<s1){
            return NULL;
        }
        int i,len;
        for(i=s1;i<e1&&in[i]!=post[e2];i++);
        len = i - s1;
        TreeNode* root = new TreeNode(post[e2]);
        root->left = createTree(in,s1,s1+len-1,post,s2,s2+len-1);
        root->right = createTree(in,s1+len+1,e1,post,s2+len,e2-1);
        return root;  
    }
};