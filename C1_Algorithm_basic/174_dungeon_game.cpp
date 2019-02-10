#include<iostream>
#include<vector>

using namespace std;
int m = 10;
int n = 10;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      //1.initial
      int m = dungeon.size();
      int n = dungeon[0].size();
      vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
      //2.dp pro
      dp[m-1][n] = 1;  //cmp
      for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
          int tmp = min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
          dp[i][j] = max(tmp,1);
        }
      }
      return dp[0][0];
    }
};

int main(){
    vector<vector<int>> dp(m+1, vector<int>(n+1,INT_MAX));
    int m = dp.size();
    int n = dp[0].size();
    cout<<"m1 "<<m<<" "<<"n1 "<<n<<endl;
    dp[m1-1][n1] = 1;
    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}