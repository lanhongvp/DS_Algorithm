#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(n==-1){
            return (1/x);
        }
        double ans = myPow(x,n>>1);
        ans *= ans;
        if((n&0x1)==1)
            ans *= x;
        return ans;
    }
};

int main(){
    double ans;
    double x;
    int n;
    x = 2.0;
    n = -4;
    ans = Solution().myPow(x,n);
    cout<<"ans "<<ans;
}