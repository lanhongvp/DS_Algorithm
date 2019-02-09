#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        start
        0 1                 2               3
        1 2 *     3          1      3        1     2
        2 3      2          3      1        2     1
        3  */
		//tmp     1
		
        int n = nums.size();
        dfs(0,nums,n, 0);
        return result;
    }
    
    void dfs(int idx,vector<int>& nums,int n, int depth){
        depth++;
        if(idx==n){
            result.push_back(tmp);
            cout<<"ha"<<endl;
            return;
        }else{
            for(int i=idx;i<n;i++){ 
                cout<<"idx "<<idx<<" ";    // depth = 1
                tmp.push_back(nums[idx]);   //nums[0]  nums[1]  nums[2]
                cout << "depth: " << depth << " ";
                cout << "nums:" << nums[idx] << " i:" << i << endl;
                dfs(idx+1,nums,n, depth);
                tmp.pop_back();
            }
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