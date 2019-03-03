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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.size()==0||post.size()==0)
            return NULL;
       return createTree(pre,0,pre.size()-1,post,0,post.size()-1);
    }
    
    TreeNode* createTree(vector<int>& pre,int s1,int e1,vector<int>& post,int s2,int e2){
        //cout<<"s1 "<<s1<<" "<<"e1"<<" "<<e1<<" ";
        //cout<<"s2 "<<s2<<" "<<"e2"<<" "<<e2<<endl;
        if((e1<=s1) && (e2<s2)){
            return NULL;
        }
        //确定左右子树位置
        TreeNode* root = new TreeNode(pre[s1]);
        if(e2<=s2||e1<=s1){
            //cout<<"ha ";
            return root;
        }
        int len,i;
        for(i=s2;i<=e2 && post[i]!=pre[s1+1];i++);
        len = i - s2 + 1;
        //cout<<"len "<<len<<" ";
        root->left = createTree(pre,s1+1,s1+len,post,s2,s2+len-1);
        root->right = createTree(pre,s1+len+1,e1,post,s2+len,e2-1);
        return root;
    }
};