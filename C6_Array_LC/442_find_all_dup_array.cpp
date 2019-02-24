#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();          
        //vector<int> ans;
        set<int> tmp;
        //if(n==0) return ans;
        for(int i=0;i<n;i++){
            while(nums[i]!=(i+1)){
                if(nums[i]==nums[nums[i]-1]){
                    tmp.insert(nums[i]);
                    break;
                }else{
                    swap(nums[i],nums[nums[i]-1]);
                }
            } 
        }
        //ans.assign(tmp.begin(),tmp.end());
        vector<int> ans(tmp.begin(),tmp.end());
        return ans;
    }
};

int main(){
    vector<int> nums;
    vector<int> ans;
    nums = {4,3,2,7,8,2,3,1};
    ans = Solution().findDuplicates(nums);
    for(auto i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}