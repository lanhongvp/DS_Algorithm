#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nums1;
vector<int> nums2;

class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      //1.initial
      // int m=nums.size(),n=nums.size();
      
      //main pro
      nums1.insert(nums1.end(),nums2.begin(),nums2.end());
      sort(nums1.begin(),nums1.end());
      int n = nums1.size();
      int mid_pos = n/2;
      double mid_value;
      if(n%2==0){
        mid_value = ((double)nums1[mid_pos-1]+(double)nums1[mid_pos])/2;
      }else{
        mid_value = nums1[mid_pos];
      }
      return mid_value;    
    }
};

int main(){
    nums1 = {1,2};
    nums2 = {3,5};

    double res = Solution().findMedianSortedArrays(nums1,nums2);
    cout<<"mid "<<res;
    for(unsigned int i=0;i<nums1.size();i++)
        cout<<" "<<nums1[i]<<" ";
}