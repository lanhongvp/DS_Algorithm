#include<iostream>
#include<vector>
using namespace std;

int cnt = 0;
int n;

class inverseCnt{
public:
    void merge(vector<int>& nums,int L1,int R1,int L2,int R2){
        int i = L1,j = L2,idx = 0;
        vector<int> tmp;
        int n = (R1-L1+1)+(R2-L2+1);
        tmp.resize(n);
        while((i<=R1)&&(j<=R2)){
            if(nums[i]<nums[j]){
                tmp[idx++] = nums[i++];
            }else{
                tmp[idx++] = nums[j++];
                cnt++;
            }
        }
        while(i<=R1){
            if(nums[i]>nums[j]){
                //cnt++;
            }
            tmp[idx++] = nums[i++];
        }
        while(j<=R2)
            tmp[idx++] = nums[i++];
        for(int i=0;i<n;i++)
            nums[L1+i] = tmp[i];
    }

    void divide(vector<int>& nums,int L,int R){
        if(L<R){
            int M =(L+R)/2;
            divide(nums,L,M);
            divide(nums,M+1,R);
            merge(nums,L,M,M+1,R);
        }
    }
};

int main(){
    vector<int> nums;
    nums = {2,1,3};
    n = nums.size();
    inverseCnt().divide(nums,0,n-1);
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    cout<<"cnt "<<cnt;
}