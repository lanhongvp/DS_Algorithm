#include<iostream>
#include<vector>
using namespace std;

class sort{
public:
    const int maxsize = 100;
    void merge(vector<int>& A,int l1,int r1,int l2,int r2){
        int i = l1;
        int j = l2;
        vector<int> tmp;
        tmp.resize(maxsize);
        int idx = 0;
        while(i<=r1 && j<=r2){
            if(A[i]<=A[j]){
                tmp[idx++] = A[i];
                i++;
            }else{
                tmp[idx++] = A[j];
                j++;
            }
        }
        while(i<=r1) tmp[idx++] = A[i++];
        while(j<=r2) tmp[idx++] = A[j++];
        for(int i=0;i<idx;i++){
            A[l1+i] = tmp[i];
        }
    }

    void merge_sort(vector<int>& nums,int l,int r){
        if(l<r){
            int mid = (l+r)/2;
            merge_sort(nums,l,mid);
            merge_sort(nums,mid+1,r);
            merge(nums,l,mid,mid+1,r);
        }
    }

    int part(vector<int>& nums,int l,int r){
        int tmp = nums[l];
        while(l<r){
            while(l<r && nums[r]>tmp) r--;
            nums[l] = nums[r];
            while(l<r && nums[l]<tmp) l++;
            nums[r] = nums[l];
        }
        nums[l] = tmp;
        return l;   
    }

    void quick_sort(vector<int>& nums,int l,int r){
        if(l<r){
            int pos = part(nums,l,r);
            quick_sort(nums,l,pos-1);
            quick_sort(nums,pos+1,r);
        }
    }
};

int main(){
    vector<int> nums = {3,4,1,2,8,9,10,7,11,5};
    // sort().merge_sort(nums,0,9);
    sort().quick_sort(nums,0,9);
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
}