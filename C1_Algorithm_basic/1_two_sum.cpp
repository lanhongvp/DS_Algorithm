
//dfs
class Solution {
public:
    vector<int> tmp;    
    vector<int> ans;
    int n;
    vector<int> twoSum(vector<int>& nums, int target) {
        n = nums.size();
        dfs(0,target,0,nums);
        return ans;
    }
    
    void dfs(int idx,int t,int sum,vector<int>& nums){
        if(sum==t){
            ans = tmp;
            return;
        }else{
            for(int i=idx;i<n;i++){
                tmp.push_back(i);
                dfs(i+1,t,sum+nums[i],nums);
                tmp.pop_back();
                
            }
        }
    }
};
//hash map
class Solution1 {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> numsMap;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int cmp = target - nums[i];
            if(numsMap.find(cmp)!=numsMap.end()){
                ans.push_back(numsMap[cmp]);
                ans.push_back(i);
                break;
            }else{
                numsMap[nums[i]] = i;
            }
        }
        return ans;
    }
};