#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      //Initial
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      int dp[m][n]={0};
      //Corner case
      if(m==0)
        return 0;
      if(obstacleGrid[0][0]==1)
        return 0;
      //State Transform
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(obstacleGrid[i][j]==1){
            dp[i][j] = 0;
            continue;
          }
          if(i==0&&j==0)
            dp[i][j] = 1;
          else{
            if(i==0){
              if(obstacleGrid[0][j-1]==1)
                dp[0][j]=0;
              else
                dp[0][j]=dp[0][j-1];
            }
            else if(j==0){
              if(obstacleGrid[i-1][0]==1)
                dp[i][0]=0;
              else
                dp[i][0]=dp[i-1][0];
            }
            else if(i>0&&j>0){
              cout<<"i "<<i<<" j "<<j<<" ";
              dp[i][j] = dp[i-1][j]+dp[i][j-1];
              cout<<"dp "<<dp[i][j]<<endl;
            }
          }         
          }
        }
      return dp[m-1][n-1];
      }
};

int main(){
    //int m=3,n=2;
    vector<vector<int>> obstacleGrid;
    obstacleGrid = {{0,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int cnt = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout<<"cnt "<<cnt;
}