#【2】排序算法小总结---归并/快速排序
- 待排序序列
    - ${66,12,33,57,64,27,18}$
- 升序排列
- 二路归并/简单快排完整代码
```cpp
#include<iostream>
#include<vector>
using namespace std;

class Sort{
public:
    void merge(vector<int>& A,int L1,int R1,int L2,int R2){
        vector<int> tmp;
        int n = (R1-L1+1)+(R2-L2+1);
        tmp.resize(n);
        int idx = 0;
        int i = L1;
        int j = L2;
        while(i<=R1 && j<=R2){
            if(A[i]<=A[j]){
                tmp[idx++] = A[i++];
            }else{
                tmp[idx++] = A[j++];
            }
        }
        while(i<=R1) tmp[idx++] = A[i++];
        while(j<=R2) tmp[idx++] = A[j++];
        for(int i=0;i<n;i++){
            A[L1+i] = tmp[i];
        }
    }

    void mergeSort(vector<int>& A,int L,int R){
        if(L<R){
            int M = (L+R)/2;
            mergeSort(A,L,M);
            mergeSort(A,M+1,R);
            merge(A,L,M,M+1,R);
        }
    }

    int findPivot(vector<int>& A,int L,int R){
        int tmp = A[L];
        while(L<R){
            while((A[R]>tmp) && (L<R)){
                R--;
            }
            A[L] = A[R];
            while((A[L]<=tmp) && (L<R)){
                L++;
            }
            A[R] = A[L];
        }
        A[L] = tmp;
        return L;
    }

    void quickSort(vector<int>& A,int L,int R){
        if(L<R){
            int pos = findPivot(A,L,R);
            quickSort(A,L,pos-1);
            quickSort(A,pos+1,R);
        }
    }
};

int main(){
    vector<int> A;
    A = {66,12,33,57,64,27,18};
    int n = A.size();
    //归并排序
    // Sort().mergeSort(A,0,n-1);
    //快速排序
    Sort().quickSort(A,0,n-1);    
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
```
## 4 归并排序
### 4.1 主要思想及原理
- 基于**归并(分治)**的基本思想，本篇博客主要介绍最基本的**2-路归并排序**
- 原理
    - 将序列两两分组，将序列归并为$[\frac{n}{2}]$个组，然后组内单独排序
    - 将这些组两两归并，生成$[\frac{n}{4}]$个组，然后组内再单独排序
    - 以此类推，**直到只剩下一个组为止**
- 时间复杂度
    - $O(nlog(n))$
### 4.2 归并排序图解
![Markdown](http://i2.bvimg.com/673646/3e76551fc526bb0a.jpg)

### 4.3 递归代码分析
```cpp
void merge(vector<int>& A,int L1,int R1,int L2,int R2){
    vector<int> tmp;
    int n = (R1-L1+1)+(R2-L2+1);
    tmp.resize(n);
    int idx = 0;
    int i = L1;
    int j = L2;
    while(i<=R1 && j<=R2){
        if(A[i]<=A[j]){
            tmp[idx++] = A[i++];
        }else{
            tmp[idx++] = A[j++];
        }
    }
    while(i<=R1) tmp[idx++] = A[i++];
    while(j<=R2) tmp[idx++] = A[j++];
    for(int i=0;i<n;i++){
        A[L1+i] = tmp[i];
    }
}

void mergeSort(vector<int>& A,int L,int R){
    if(L<R){
        int M = (L+R)/2;
        mergeSort(A,L,M);
        mergeSort(A,M+1,R);
        merge(A,L,M,M+1,R);
    }
}

```
![Markdown](http://i2.bvimg.com/673646/9a7c26851d68e345.png)

## 5 快速排序
### 5.1 主要思想及原理
- 子问题
    - 对于一个原始待排序数组，随机或者有规律的选择一个**pivot**
    - 调整数组中元素的位置，保证**pivot**左侧的数都小于等于**pivot**，右侧的数都大于等于**pivot**