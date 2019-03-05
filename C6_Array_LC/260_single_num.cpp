#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> singleNumber(vector<int>& nums){
        int n = nums.size();
        int resultXor=0;
        int num1=0,num2=0;
        vector<int> ans;
        if(n<1){
            return ans;
        }
        for(int i=0;i<n;i++){
            resultXor ^= nums[i];
        }
        int rOneIdx = rightOneIdx(resultXor);
        for(int i=0;i<n;i++){
            if(isOne(nums[i],rOneIdx)){
                num1 ^= nums[i];
            }else{
                num2 ^= nums[i];
            }
        }
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
    
    int rightOneIdx(int num){
        int idx = 0;
        while((num&1)==0){
            num = num>>1;
            idx++;
        }
        return idx;
    }

    bool isOne(int num,int oneIdx){
        num = num>>oneIdx;
        return(num&1);
    }
};


int main(){
    vector<int> nums;
    vector<int> ans;
    nums = {2,4,6,4,5,5};
    // int pos = Solution().rightOneIdx(4);
    // cout<<"pos "<<pos;
    ans = Solution().singleNum(nums);
    for(int i=0;i<2;i++)
        cout<<ans[i]<<" ";
}