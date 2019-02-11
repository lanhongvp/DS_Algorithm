#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int n;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

class Solution1 {
public:
    int n;
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        int ans;
        vector<int> v;
        v.push_back(0x80000000);
        for(int i=0;i<n;i++)
            v.push_back(nums[i]);
        ans = dfs(0,v)-1;
        return ans;
    }
    int dfs(int idx,vector<int>& nums){
        //depth++;
        if(idx>n){
            return 0;
        }
        int ans = 0;
        for(int i=idx;i<=n;i++){
            if(nums[i]>nums[idx]){
                int tmp = dfs(i,nums);
                ans = max(ans,tmp);
            }
        }
        cout<<"haha "<<idx<<endl;
        return ans+1;
    }   
};

int main(){
    vector<int> nums;
    nums = {10,9,11};
    int ans = Solution1().lengthOfLIS(nums);
    cout<<"ans "<<ans;
}