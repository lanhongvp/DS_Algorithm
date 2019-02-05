#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
      //1.initial
      const int cmp_num=0x55555555;
      bool result=false;
      //2.corner case
      if(num<0) result=false;
      //3.main pro
      if((cmp_num&num) && ((num&(num-1))==0)) result=true;
      return result;
    }
};

int main(){
    int num;
    cin>>num;
    
    bool res = Solution().isPowerOfFour(num);
    cout<<"res "<<res;
}