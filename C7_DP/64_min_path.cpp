#include<iostream>
#include<vector>

using namespace std;
const int size=3;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //Initial
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];  //状态数组存储
        //corner case
        //if(grid)
        //状态转变过程
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(i==0 && j==0)
              dp[i][j] = grid[i][j];
            else if(i==0)
              dp[i][j] = grid[i][j]+dp[i][j-1];
            else if(j==0)
              dp[i][j] = grid[i][j]+dp[i-1][j];
            else
              dp[i][j] = min(grid[i][j]+dp[i-1][j],grid[i][j]+dp[i][j-1]);
          }
        }
      return dp[m-1][n-1];
    }
};

int main(){
    vector<vector<int> > grid;
    vector<int> dist_1,dist_2,dist_3;

    dist_1 = {1,3,1};
    dist_2 = {1,5,1};
    dist_3 = {4,2,1};
    grid.push_back(dist_1);
    grid.push_back(dist_2);
    grid.push_back(dist_3);

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            cout<<grid[i][j]<<" ";
    }
    cout<<"size "<<grid[0].size()<<" ";
    int result = Solution().minPathSum(grid);
    cout<<"result "<<result;

}