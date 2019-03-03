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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0)
            return NULL;
        return createTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    
    TreeNode* createTree(vector<int>& pre,int s1,int e1,vector<int>& in,int s2,int e2){
        // if(e2>s2)
        //     return NULL;
        if(e1<s1||e2<s2){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[s1]);
        int i,cnt;
        for(i=s2;i<=e2&&pre[s1]!=in[i];i++);
        //cout<<"i "<<i<<" ";
        cnt = i - s2;
        //cout<<"cnt "<<cnt<<endl;
        root->left = createTree(pre,s1+1,s1+cnt,in,s2,s2+cnt);
        root->right = createTree(pre,s1+cnt+1,e1,in,s2+cnt+1,e2);
        return root;
    }
};