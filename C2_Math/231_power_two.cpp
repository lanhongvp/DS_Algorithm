#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        //1.initial
        bool result=false;
        int b2 = 1;
        //2.corner case
        if(n==0) return false;
        if(n==1) return true;
        //3.main pro
        for(int i=0;i<31;i++){
            // int tmp = n|b2;  
            // cout<<"tmp "<<tmp<<" ";
            // cout<<"b2 "<<b2<<" ";
          if((n|b2)==b2){
            // cout<<"xi";
            result=true;
            break;
          }
          else{
            b2 = b2<<1;
          }
        //   cout<<endl;
        }
      return result;
    }
};

int main(){
    int num;
    cin>>num;
    bool result = Solution().isPowerOfTwo(num);
    cout<<"res "<<result;
}