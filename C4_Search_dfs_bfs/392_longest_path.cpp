#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int X[4] = {0,0,1,-1};    
    int Y[4] = {1,-1,0,0};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int vis[n][m] = {0};
        if(matrix.empty()) return 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0)
                ans = max(ans,dfs(i,j,matrix,n,m));
            }
        }
        return ans;
    }
    
    int dfs(int x,int y,vector<vector<int>>& mat,int n,int m){
        int ans = 0;
        for(int i=0;i<4;i++){
            int newx = x+X[i];
            int newy = y+Y[i];
            if(check(newx,newy,n,m)){
                cout<<"x "<<x<<" y "<<y<<endl;
                if(mat[newx][newy]>mat[x][y]){
                    ans = max(dfs(newx,newy,mat,n,m),ans)+1;
                    //cout<<"ans "<<ans<<endl;   
                }
            }
        }
        return ans;
    }
    
    bool check(int x,int y,int n,int m){
        if((x>=0&&y>=0) && (x<n && y<m))
            return true;
        else
            return false;
    }
};

int main(){
    vector<vector<int>> mat;
    mat = {};
    int ans = Solution().longestIncreasingPath(mat);
    cout <<"ans "<<ans;
}

