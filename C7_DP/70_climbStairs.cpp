#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs1(int n) {
        //Initial
        int dp[n]={0};
        //Basical and corner case

        //State transform
        for(int i=0;i<=n;i++){
            if(i==0)
                dp[i]=0;
            else if(i==1)
                dp[i]=1;
            else if(i==2)
                dp[i]=2;
            else{
                dp[i] = dp[i-1]+dp[i-2];
            }
        }
        return dp[n];
    }

    int climbStairs(int n){
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        else
            return climbStairs(n-1)+climbStairs(n-2);
    }
};

int main(){
    int result = Solution().climbStairs1(5);
    cout <<result;
}