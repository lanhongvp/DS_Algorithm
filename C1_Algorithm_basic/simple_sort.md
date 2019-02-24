# 【1】排序算法小总结---冒泡/选择/插入排序
好久不总结，今天简单总结一下几种常见的排序算法，方便后续巩固和复习。接下来主要介绍六种排序算法：**冒泡排序，选择排序，插入排序，堆排序，归并排序和快速排序**，本次排序算法均以**升序为例**。
话不多说，整体代码先瞅一下，然后今天主要简单配合图解看看**冒泡/选择和插入排序算法。**
```cpp
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
```

## 1 冒泡排序
- 冒泡排序的本质在于交换，即每次通过交换的方式把当前剩余元素的最大值移动到一端，而当剩余元素减少为0时，排序结束
- 注意
    - 相邻元素进行交换
- 图解
    
    ![bubble_sort](http://i2.bvimg.com/673646/ad7e3e113c9a4f7a.png)
- 冒泡代码
```cpp
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
```
## 2 简单选择排序
- 对一个序列A中的元素A[0]~A[n-1]，令i从0~(n-1)枚举，进行n趟操作，每趟从待排序部分[i,n-1]中选择最小的元素，令其与待排序部分的第一个元素A[i]进行交换，这样元素A[i]就会与当前有序区间[0,i-1]形成新的有序区间[0,i]
- 图解

    - ![select_sort](http://i2.bvimg.com/673646/ae890ec5c1abef3e.png)
- 简单选择代码
```cpp
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
```
## 3 直接插入排序
- 对一个序列A的前i-1个元素A[0]~A[n-1]，令i从1到n-1枚举，进行n-1趟操作。假设某一趟时，序列A的前i-1个元素A[0]~A[i-1]已经有序，而范围[i,n-1]还未有序，那么该趟从范围[0,i-1]寻找某个位置j，使得将A[i]插入位置j之后 **（此时A[j]~A[i-1]会后移一位至A[j+1]~A[i]）**，范围[0,i]有序
- 图解插入排序

    ![insert_sort](http://i1.bvimg.com/673646/34cc43ccd8962c6e.png)
- 插入排序代码
```cpp
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
```

