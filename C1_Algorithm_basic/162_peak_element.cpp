#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      //1.initial
      int n=nums.size();
      int idx;
  
      //2.corner case
      if(n==0||(n==1 &&nums[0]==INT_MIN)) return 0;
      //3.main pro
      for(int i=0;i<n;i++){
        if(i==0 && nums[i+1]<=nums[i]){
          idx=0;
          break;
        }
        if(i==(n-1) && nums[i-1]<=nums[i]){
          idx=n-1;
          break;
        }
        if(i>0 && nums[i+1]<=nums[i] && nums[i-1]<=nums[i]){
          idx = i;
          break;
        }
      }
      return idx;
    }
};

int main(){
    vector<int> nums;
    nums = {1,2,3,1};

    int res = Solution().findPeakElement(nums);
    cout<<"res "<<res;
}