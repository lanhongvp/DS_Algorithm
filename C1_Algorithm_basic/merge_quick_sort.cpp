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

    void findPivot1(vector<int>& A,int tmp){
        int n = A.size();
        int L = 0;
        int R = n-1;
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
    }

    void quickSort1(vector<int>& A){
        int n = A.size();
        for(int i=0;i<n;i++){
            findPivot1(A,A[i]);
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
    Sort().quickSort1(A);    
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}