#include<iostream>
#include<vector>

using namespace std;

class simple_sort{
public:
    void bubble_sort(vector<int>& nums,int n){
        for(int i = 0;i < n;i++){
            for(int j = i;j < n;j++){
                if(nums[i] > nums[j]){
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
    }

    void select_sort(vector<int>& nums,int n){
        for(int i = 0;i < n;i++){
            int k = i;
            for(int j = i;j < n;j++){
                if(nums[j] < nums[k]){
                    k = j;
                }
            }
            int tmp = nums[i];
            nums[i] = nums[k];
            nums[k] = tmp;
        }
    }

    void insert_sort(vector<int>& nums,int n){
        for(int i = 1;i < n;i++){
            int j = i;
            int tmp = nums[i];
            //此处的while循环，保证找到合适的插入位置
            //并且较大的元素依次后移
            while(j>0 && tmp<nums[j-1])
            {
                nums[j] = nums[j-1];
                j--;
            }
            nums[j] = tmp;
        }
    }
};

int main(){
    vector<int> nums;
    nums = {3,2,1,9,6,8,5,7};
    int n = nums.size();
    //冒泡排序
    //simple_sort().bubble_sort(nums,n);
    //选择排序
    //simple_sort().select_sort(nums,n);
    //插入排序
    simple_sort().insert_sort(nums,n);
    for(int i = 0;i < n;i++){
        cout<<nums[i]<<" ";
    }
}