#include<iostream>
#include<vector>

using namespace std;
//输入数字n，按顺序打印出从1到最大的n位十进制数
class Solution{
public:
    void Print1ToMaxOfDigits(int n){
        vector<int> nums(n,0);
        //vector<int> fnums(n,9);
        while(!addOne(nums)){
            for(int i=0;i<n;i++){
                cout<<nums[i];
            }
            cout<<" ";
        }
    }

    bool addOne(vector<int>& nums){
        int idx = nums.size()-1;
        int carry = 1;
        while((carry!=0) && (idx>=0)){
            nums[idx] += carry;
            carry = nums[idx]/10;
            nums[idx] %= 10;
            idx--;
        }
        if((carry>0) && (idx==-1)){
            //cout<<"haha";
            return true;
        }
        return false;
    }
};

int main(){
    Solution().Print1ToMaxOfDigits(3);
}