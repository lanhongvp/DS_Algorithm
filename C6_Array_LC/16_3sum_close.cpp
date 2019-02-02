#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int hsize = nums.size();
        //int close_sum = 0x3fffffff;
        int close_sum = nums[0]+nums[hsize-1]+nums[hsize-2];
        for(int i=hsize-1;i>=2;i--){
            int left=0,right=i-1;
            while(left<right){
                int tmp_sum = nums[i]+nums[left]+nums[right];
                if(abs(close_sum-target)>abs(tmp_sum-target)){
                    close_sum = tmp_sum;
                    cout<<"close "<<close_sum<<" ";
                    cout<<"i "<<i<<" ";
                }
                if(tmp_sum>target)
                    right--;
                else if(tmp_sum<target)
                    left++;
                else if(tmp_sum==target)
                    return (target);
            }
        }
        return close_sum;
    }

int main(){
    vector<int> nums={1,1,-1,-1,3};
    int result = threeSumClosest(nums,-1);
    cout<<result;
}