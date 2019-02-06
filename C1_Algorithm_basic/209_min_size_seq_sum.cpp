#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      //1.initial
      int n = nums.size();
      int L = 0;
      int cnt = 1;
      int sum = 0;
      map<int,int> ans;
      //2.corner case
      if(n==0) return 0;
      //3.main pro
      for(int i=0;i<n;){
        if(sum+nums[i]<s){
          cnt++;
          sum += nums[i];
          cout <<"i "<<i<<" ";
          cout <<"sum1 "<<sum<<" ";
          i++;
        }else if(sum+nums[i]>s){
          i = L++;
          cnt = 1;
          sum = nums[L];
          cout <<"sum2 "<<sum<<" ";
          cout<<"L "<<L<<" ";
          continue;
        }else if(sum+nums[i]==s){
          cout<<"cnt "<<cnt<<" ";
          cnt++;
          if(ans.find(s)!=ans.end()){
            if(ans[s]>cnt) ans[s] = cnt;
          }else
            ans[s] = cnt;
            i++;
        }
      }
      if(ans.find(s)==ans.end()) return 0;
      else return ans[s];
    }
};

int main(){
    vector<int> nums;
    nums = {1,4,4};
    int s = 7;
    int ans = Solution().minSubArrayLen(s,nums);
    cout<<"ans "<<ans;

}