#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int left=0;
      int right = nums.size()-1;
      //得到旋转点
      while(left<right){
        int mid=(left+right)/2;
        if(nums[mid]>nums[right])
          left = mid+1;
        else
          right = mid;
      }
      int ro_id = right;
      int left1=0,right1=ro_id-1;
      int left2=ro_id,right2=nums.size()-1;
      int tmp_idx1 = find_idx(nums,left1,right1,target);
      if(tmp_idx1!=-1)
        return tmp_idx1;
      else{
        int tmp_idx2 = find_idx(nums,left2,right2,target);
        if(tmp_idx2!=-1)
          return tmp_idx2;
        else
          return -1;
      }
      //return -1;
    }
    int find_idx(vector<int>& nums,int tmp_left,int tmp_right,int target){
      if(nums[tmp_left]>target||nums[tmp_right]<target)
        return -1;
      else{
        int left = tmp_left;
        int right = tmp_right;
        while(left<=right){
          int mid=(left+right)/2;
          if(nums[mid]<target){
            left = mid+1;
          }
          if(nums[mid]>target){
            right = mid-1;
          }
          if(nums[mid]==target){
            return mid;
          }
        }
      }
    }
};

int main(){
  vector<int> nums={4,5,6,7,0,1,2};

  int se_idx = Solution().search(nums,5);
  cout<<se_idx;
}