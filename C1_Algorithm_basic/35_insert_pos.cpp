class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //1.initial
        int n = nums.size();
        int L = 0,R=n-1;
        int mid;
        int ans=-1;
        //2.corner case
        //3.main
        while(L<=R){
          mid = (L+R)/2;
          if(guess(nums,mid,target)){
            ans = mid;
            L = mid+1;
          }else{
            R = mid-1;
          }
        }        
      return ans+1;
    }
  
    bool guess(vector<int>& nums,int mid,int target){
      bool result;
      result = (nums[mid]<target);
      return result;
    }
};