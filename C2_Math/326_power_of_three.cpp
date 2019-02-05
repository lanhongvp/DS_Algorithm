#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
      //1.initial
        bool result=false;
        double cmp3=log(3);
      //2.corner case;
        if(n<=0) result=false;
      //3.main pro
        if(fmod(log(n),log(3))==0.0) result=true;
        return result;
    }
};

int main(){
    int n;
    cin>>n;
    bool res = Solution().isPowerOfThree(n);
    cout<<res;
}