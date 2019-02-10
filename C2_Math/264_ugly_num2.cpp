#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,1);
        int a2=0,a3=0,a5=0;
        for(int i=1;i<n;i++){
            int next2 = 2*dp[a2];
            int next3 = 3*dp[a3];
            int next5 = 5*dp[a5];
            dp[i] = min(next2,min(next3,next5));
            if(dp[i]==next2) a2++;
            if(dp[i]==next3) a3++;
            if(dp[i]==next5) a5++;
        }
        return dp[n-1];
    }
};

int main() {
    int num;
    cin>>num;

    int res = Solution().nthUglyNumber(num);
    cout<<res;
}