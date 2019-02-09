#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    //set<vector<int>> s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> t;
        result.push_back(t);
        dfs(0,nums,n);
        return result;
    }
    
    void dfs(int idx,vector<int>& nums,int n){  // idx [0,1)
        // i:function variable
        for(int i=idx;i<n;i++){
            if((nums[i]==nums[i-1])&&(i>idx))
                continue;
            tmp.push_back(nums[i]);
            dfs(i+1,nums,n);
            result.push_back(tmp);
            tmp.pop_back();
            //return;
        }
    }
};

int main(){
    vector<vector<int>> ans;
    vector<int> nums;
    nums = {1,2,2};
    ans = Solution().subsetsWithDup(nums);
    cout<<ans.size();
}