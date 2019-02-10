#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      //1.initial
      int n = nums.size();
      int sum = 0;
      int L=0,R=0;
      int cnt = INT_MAX;
      //2.corner case
      if(n==0) return 0;
      //3.main pro
      while(L<n){
        if(sum<s && R<n){
          sum += nums[R];         
          R++;
        }else{
          sum -= nums[L];
          L++;
        }
        if(sum>=s) cnt = min(cnt,(R-L));
      }
      if(cnt==INT_MAX) return 0;
      else return cnt;
    }
};

int main(){
    vector<int> nums;
    nums = {1,4,4};
    int s = 7;
    int ans = Solution().minSubArrayLen(s,nums);
    cout<<"ans "<<ans;

}