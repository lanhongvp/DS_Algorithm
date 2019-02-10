#include<iostream>
#include<vector>

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
          cout<<"sum1 "<<sum<<" "; 
          cout<<"R "<<R<<" ";      
        }else{
          sum -= nums[L];
          L++;
          cout<<"sum2 "<<sum<<" ";
          cout<<"L "<<L<<" ";
        }
        if(sum>=s) cnt = min(cnt,(R-L));
        cout<<"cnt "<<cnt<<endl;
      }
      if(cnt==INT_MAX) return 0;
      else return cnt;
    }
};

int main(){
    int s = 7;
    vector<int> nums;
    nums = {2,3,1,2,4,3};
    int cnt = Solution().minSubArrayLen(s,nums);
    cout<<"cnt "<<cnt;
}