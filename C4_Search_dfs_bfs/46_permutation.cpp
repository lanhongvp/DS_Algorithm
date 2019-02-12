#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void DFS(vector<int>& nums)
    {
      // if meiman, fang xia yige shu
      // man, shuchu jieguo
      /*
      start
      0           1             2
      1   2       0   2         1   0
      2   1       2   0         0   1      
      */
    for(int i = 0; i < N; i++)
    {
        if(vis[i] == 0){
            vis[i] = 1;
            permutation.push_back(nums[i]);
            if(permutation.size() == N)
            {
                result.push_back(permutation);
            }
            else
            {
                DFS(nums);
            }
            vis[i] = 0;
            permutation.pop_back();
        }
    }
    return;
}
};

class Solution1 {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<int> vis;

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> t(n,0);
        vis.resize(n);
        vis = t;
        dfs(nums);
        return ans;
    }
    
    void dfs(vector<int>& nums){
        if(tmp.size()==n){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i] = 1;
                tmp.push_back(nums[i]);
                dfs(nums);
                vis[i] = 0;
                tmp.pop_back();   
            }
        }
        
    }
};

int main(){
    vector<vector<int>> result;
    vector<int> nums = {1,2,3};
    result = Solution().permute(nums);
    cout<<result.size();
}