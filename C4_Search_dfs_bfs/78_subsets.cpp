#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<int> vis;
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        start
        1                 2               3
        2      3          1      3        1     2
        3      2          3      1        2     1
        */
        int n = nums.size();
        dfs(0,nums,n);
        return result;
    }
    
     void dfs(int idx,vector<int>& nums,int n){
       for(int i=idx;i<n;i++){
            tmp.push_back(nums[i]);
            //cout<<"i "<<i<<" "<<endl;
            dfs(i+1,nums,n);
            result.push_back(tmp);
            tmp.pop_back();
       }
    }   
};

int main(){
    vector<vector<int>> ans;
    vector<int> nums;
    nums = {1,2,3};
    ans = Solution().subsets(nums);
    cout<<ans.size();

}