#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxsize = 105;

struct node{
    char data;
    node* left;
    node* right;
};
//char preorder[maxsize],inorder[maxsize];
char preorder[maxsize] = {'A','B','C'};
char inorder[maxsize] = {'B','A','C'};    
int n;

node* create_tree(int pre_left,int pre_right,int in_left,int in_right){
    if(pre_left>pre_right)
        return NULL;
    
    node* root = new node;
    root->data = preorder[pre_left];
    //printf("%c\n",root->data);
    int k;
    for(k=in_left;k<=in_right;k++){
        //printf("haha");
        if(inorder[k]==preorder[pre_left])
            break;
    }
    //printf("k is %d",k);
    int num_left = k - in_left;
    //printf("num_left is %d\n",num_left);

    //递归构建左子树
    root->left = create_tree(pre_left+1,pre_left+num_left,in_left,k-1);
    printf("left: %d %d %d %d\n",pre_left,pre_right,in_left,in_right);
    //递归构建右子树
    root->right = create_tree(pre_left+num_left+1,pre_right,k+1,in_right);
    printf("right: %d %d %d %d\n",pre_left,pre_right,in_left,in_right);
    printf("xi\n");

    //返回根结点
    return root; 
}


void post_order(node* root){
    if(root==NULL)
        return;
    post_order(root->left);
    post_order(root->right);

    printf("%c",root->data);
}

int main(){
    //int n;
    scanf("%d",&n);
    
    //输入先序遍历的结果
    // for(int i=0;i<n;i++){
    //     scanf("%c",&preorder[i]);
    //     //preorder[i] = node_value;
    // }

    //输入中序遍历的结果
    // for(int i=0;i<n;i++){
    //     scanf("%c",&inorder[i]);
    //     //inorder[i] = node_value;
    // }

    // int pre_left = 0,pre_right = n-1;
    // int in_left = 0,in_right = n-1;
    //node* root  = new node;
    node* root = create_tree(0,n-1,0,n-1);

    //post_order(root);
}

/*
6
ABDECF
DBEACF
*/