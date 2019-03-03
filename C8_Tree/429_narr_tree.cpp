/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        vector<int> tmp;
        if(root==NULL)
            return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            //q.pop();
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                for(auto child:node->children){
                    q.push(child);
                }
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};