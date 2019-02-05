class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
      //1.initial
      int n=nums.size();
      long long L=0,R=0;
      long long ans,mid;
      for(int i=0;i<n;i++){
        R += nums[i];
      }
      //2.corner case
      //3.main pro
      while(L<=R){
        mid = (L+R)/2;
        if(guess(nums,m,mid)){
          ans = mid;
          R = mid - 1;
        }else{
          L = mid + 1;
        }
      }
      return ans;
    }
  
    bool guess(vector<int>& nums, int m, long long mid){
      long long sum = 0;
      for(int i=0;i<nums.size();i++){
        if(sum+nums[i]>mid){
          m--;
          sum = nums[i];
          if(nums[i]>mid) return false;
        }else{
          sum += nums[i];
        }
      }
      return m>=1;
    }
};