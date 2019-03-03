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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> s1,s2;
        if(root==NULL)
            return ans;
        s1.push(root);
        int depth = 0;
        while(!s1.empty()||!s2.empty()){
            if((depth%2==0)){
                int n = s1.size();
                vector<int> tmp;
                while(n){
                    TreeNode* topNode = s1.top();
                    //cout<<"s1 "<<topNode->val<<" ";
                    //if(topNode){
                        tmp.push_back(topNode->val);
                        s1.pop();
                        if(topNode->left)
                            s2.push(topNode->left);
                        if(topNode->right)
                            s2.push(topNode->right);
                        n--;   
                    //} 
                }
                depth++;
                ans.push_back(tmp);
            }else if((depth%2==1)){
                int n = s2.size();
                vector<int> tmp;
                while(n){
                    TreeNode* topNode = s2.top();
                    //if(topNode){
                        tmp.push_back(topNode->val);
                        s2.pop();
                        if(topNode->right)
                            s1.push(topNode->right);
                        if(topNode->left)
                            s1.push(topNode->left);
                        n--;   
                    //} 
                }
                depth++;
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};