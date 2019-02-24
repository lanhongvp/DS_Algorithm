class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans;
        int left = 0;
        int right = n-1;
        if(n==1||(nums[left]<nums[right]))
            return nums[0];
        while(nums[left]>=nums[right]){
            int mid = (left+right)/2;
            if(nums[mid]>=nums[left]){
                left = mid;
            }else if(nums[mid]<=nums[right]){
                right = mid;
            }
            if((right-left)==1){
                ans = min(nums[right],nums[left]);
                break;
            }
        }
        return ans;
    }
};