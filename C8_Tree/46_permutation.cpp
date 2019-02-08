#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  //const int maxsize = 100;
  vector<vector<int>> ans;
  int ans_tmp[100];
  int vis[100] = {0};
  //fill(vis,vis+100,0);
  
  vector<vector<int>> permute(vector<int>& nums) {
        robot(0,nums);
        return ans;
    }   
  void robot(int idx,vector<int>& nums){
    //边界条件
    vector<int> tmp_v;
    //cout<<"haha";
    if(idx>=nums.size()){
      tmp_v(ans_tmp,ans_tmp+nums.size());
      ans.push_back(tmp_v);  
      return;
    }
    //local varible
    for(int i=1;i<=nums.size();i++){
      if(vis[i]==0){
        ans_tmp[idx] = i;
        vis[i] = 1;
        robot(idx+1,nums);
        vis[i] = 0;
      }
    }
  }
};

int main(){
    vector<vector<int>> result;
    vector<int> nums = {1,2,3};
    result = Solution().permute(nums);
    cout<<result.size();
}