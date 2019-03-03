class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        if(n==0)
            return false;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        if(s.size()<nums.size())
            return true;
        else 
            return false;
    }
};