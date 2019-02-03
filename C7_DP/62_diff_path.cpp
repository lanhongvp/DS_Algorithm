#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
      //Initial
      int dp[m][n];
      //corner case
      
      //State transform
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(i==0 && j==0)
            dp[i][j] = 1;
          else if(i==0)
            dp[i][j] = 1;
          else if(j==0)
            dp[i][j] = 1;
          else
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
      }
        return dp[m-1][n-1];
    }
};

int main(){
    int m=3,n=2;
    int cnt = Solution().uniquePaths(m,n);
    cout<<"cnt "<<cnt;
}