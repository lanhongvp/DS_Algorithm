class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i;
        int ans;
        for(i=0;i<n;i+=2){
            if(i+1<n){
                if(nums[i]!=nums[i+1])
                break;
            }else if(i==n-1){
                break;
            }
        }
        return nums[i];
    }
};