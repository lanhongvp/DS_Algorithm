#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        dfs(candidates,0,0,target,n);
        return ans;
    }
    
    void dfs(vector<int>& c,int sum,int idx,int target,int n){
        if(sum==target){
            ans.push_back(tmp);
            return;
        }
        if(idx>=n || sum>target)
            return;
        tmp.push_back(c[idx]);
        dfs(c,sum+c[idx],idx,target,n);
        tmp.pop_back();
        dfs(c,sum+c[idx],idx++,target,n);
    }
};

int main(){
    vector<int> c = {2,3,5};
    vector<vector<int>> ans;
    ans = Solution().combinationSum(c,8);
    cout <<ans.size();
}