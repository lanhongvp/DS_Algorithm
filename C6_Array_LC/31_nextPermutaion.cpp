#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nsize=nums.size();
        int idx=nsize-1;
        //int flag=0;
        int right=nsize-2;
        if(nsize==2 && nums[0]==nums[1]){
            return ;
        }
        while(idx>0){
            if(nums[right]<nums[idx]){
                swap(nums[right],nums[idx]);
                sort(nums.begin()+(right+1),nums.end());
                return ;
            }
            else{
                right--;
                if(right==0 && idx!=1){
                    idx--;
                    right = idx-1;
                }
                if(idx==1 && nums[idx-1]<nums[idx]){
                    swap(nums[idx-1],nums[idx]);
                    sort(nums.begin()+1,nums.end());
                    return;
                }
                else if(idx==1 && nums[idx-1]>nums[idx]){
                    sort(nums.begin(),nums.end());
                    return;
                }
            }
        }


    }
};
class Solution1 {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        int j = 0;
        //find the first inverse number
        while(i>0 && nums[i-1]>=nums[i]){
            i--;
        }
        //exist inverse number
        if((i-1)>=0){
            j = n-1;
            //find the first larger num than the inverse num
            while(j>=0 && nums[j]<=nums[i-1]){
                j--;
            }
            swap(nums[i-1],nums[j]);
        }
        //after swap, sort the rest of the num
        sort(nums.begin()+i,nums.end());
    }
};

int main(){
    vector<int> nums={1,5,1};
    Solution().nextPermutation(nums);
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";

}