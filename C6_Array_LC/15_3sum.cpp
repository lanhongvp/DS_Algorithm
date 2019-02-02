#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        int nsize = nums.size();
        //int vis[length];
        vector<int> tmpv;
        vector<vector<int>> r_v;
        for(int i=nsize-1;i>=2;){
            int left=0,right=i-1;
            while(left<right){
                int tmp_sum = nums[left]+nums[right];
                if(tmp_sum>(-nums[i]))
                    right--;
                else if(tmp_sum<(-nums[i]))
                    left++;
                else if(tmp_sum==(-nums[i])){
                    tmpv = {nums[left],nums[right],nums[i]};
                    r_v.push_back(tmpv);
                    //保证指针右移且去除重复元素
                    do{
                        left++;
                    }while(left<right && nums[left-1]==nums[left]);
                    //保证指针左移且去除重复元素
                    do{
                        right--;
                    }while(left<right && nums[right+1]==nums[right]);
                }
            }
            do{
                i--;
            }while(i>=2 && nums[i+1]==nums[i]);
        }
        return r_v;
    }
};

    int main(){
        vector<vector<int>> result;
        vector<int> nums={-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
        result = Solution().threeSum(nums);
        for(int i=0;i<result.size();i++){
            for(int j=0;j<3;j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }