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
        dfs(0,nums,n,0);
        return result;
    }
    
     void dfs(int idx,vector<int>& nums,int n,int depth){
       depth++;
       for(int i=idx;i<n;i++){
           cout<<"idx "<<idx<<" "<<"depth "<<depth<<" ";
           cout<<"i "<<i<<" ";
            tmp.push_back(nums[i]);
            cout<<"ni "<<nums[i]<<endl;
            dfs(i+1,nums,n,depth);
            //cout<<"xi "<<idx<<" "<<endl;
            result.push_back(tmp);
            tmp.pop_back();
            //return;
       }
       return;
    }   
};
class Solution1 {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        dfs(0,nums);
        vector<int> t;
        ans.push_back(t);
        return ans;
    }
    
    void dfs(int idx,vector<int>& nums){
        for(int i=idx;i<n;i++){
            tmp.push_back(nums[i]);
            dfs(i+1,nums);
            ans.push_back(tmp);
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