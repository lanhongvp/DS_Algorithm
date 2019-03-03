class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<1)
            return 0;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                //注意除数为0   若除数为0，则和为0为真，不能求余
                //注意子数组大小至少为 2
                if(((k==0 && sum==0) || (k!=0 && sum%k==0)) && j-i>0)
                    return 1;
            }
        }
        return 0;
    }
};