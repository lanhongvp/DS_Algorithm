#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0;
        int right = -1;
        int length = nums.size() + 1;
        int sum = 0;
        //只要左边界还没到最右边，就可以继续查找合适的数组
        while (left < nums.size()) {
            //和太小，右边界继续后移，扩大范围
            if (sum < s && right + 1 < nums.size()) {
                right ++;
                sum += nums[right];
                cout<<"sum1 "<<sum<<" ";
            } else {
                sum -= nums[left] ;
                left ++;
                cout<<"sum2 "<<sum<<endl;
            }
            if (sum == s) length = min(length, right - left + 1);
        }
        if (length == nums.size() + 1) return 0;
        return length;
    }
};

int main(){
    int s = 7;
    vector<int> nums;
    nums = {2,3,1,2,4,3};
    int cnt = Solution().minSubArrayLen(s,nums);
    cout<<"cnt "<<cnt;
}