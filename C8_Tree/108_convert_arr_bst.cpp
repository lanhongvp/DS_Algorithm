/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return arr2bst(nums,0,nums.size()-1);
    }
  
    TreeNode* arr2bst(vector<int>& nums,int L,int R){
      if(L>R) return NULL;
      int mid = (L+R)/2;
      cout<<"mid "<<mid<<" ";
      TreeNode* root = new TreeNode(nums[mid]);
      root->left = arr2bst(nums,L,mid-1);
    //   cout<<"L "<<L<<" mid-1 "<<(mid-1)<<" "<<"R "<<R<<endl;
      root->right = arr2bst(nums,mid+1,R);
    //   cout<<"R "<<R;
      return root;
    }
};

int main(){
    vector<int> nums;
    nums = {-10,-3,0,5,9};
    TreeNode* root;
    root = Solution().sortedArrayToBST(nums);
}