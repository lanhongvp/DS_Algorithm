#include<iostream>
#include<vector>
#include<stack>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct snode{
    TreeNode* r;
    int state;
};

class tree{
public:
    TreeNode* create_tree(vector<int> data){
        TreeNode* r = NULL;
        for(unsigned int i=0;i<data.size();i++){
            insert(r,data[i]);
        }
        return r;
    }
    void insert(TreeNode*& r,int x){
        if(r==NULL){
            r = new TreeNode(x);
            return;
        }
        if(r->val==x) return;
        if(r->val<x) insert(r->right,x);
        if(r->val>x) insert(r->left,x);
    }
    
    void pre_order(TreeNode* r){
        if(r==NULL) return;
        cout<<r->val<<" ";
        pre_order(r->left);
        pre_order(r->right);
    }

    void traversal(TreeNode* r){
        stack<snode> s;
        snode sn;
        sn.r = r;
        sn.state = 0;
         
        while(!s.empty()||sn.r!=NULL){
            while(!s.empty()&&(sn.r==NULL||sn.state>=3)){
                sn = s.top();
                //cout<<"w_sn_val "<<sn.r->val<<" ";
                s.pop();
                sn.state++;
                //cout<<"w_state "<<sn.state<<" ";
            }
            if(sn.r==NULL || sn.state>=3){
                cout<<"ha"<<" ";
                break;
            }
            switch(sn.state){
                case 0:
                    // s.push(sn);
                    // //cout<<"0_val "<<sn.r->val<<" ";                    
                    // sn.r = sn.r->left;
                    // break;
                    cout<<sn.r->val<<" ";
                    sn.state++;
                    // s.push(sn);                    
                    break;
                case 1:
                    // cout<<sn.r->val<<" ";
                    // sn.state++;
                    // break;
                    s.push(sn);
                    sn.r = sn.r->left;
                    sn.state = 0;
                    break;
                case 2:
                    s.push(sn);
                    //cout<<"2_val "<<sn.r->val<<endl;                    
                    sn.r = sn.r->right;
                    sn.state = 0;
                    break;
                default:
                    break;
            }
        }
    }
};

int main(){
    TreeNode* root;
    vector<int> data = {5,4,7,2,3,6,8};
    root = tree().create_tree(data);
    tree().pre_order(root);
    cout<<endl;    
    tree().traversal(root);
}