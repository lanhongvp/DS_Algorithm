#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int X[4] = {0,0,1,-1};    
    int Y[4] = {1,-1,0,0};
    vector<vector<int>> vis;
    int n,m;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;
        vis.resize(n);
        int m = matrix[0].size();
        if(m==0) return 0;
        this->n = n;
        this->m = m;
        for(int i=0;i<n;i++)
            vis[i].resize(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //if(vis[i][j]==0)
                    ans = max(ans,dfs(i,j,matrix));
            }
        }
        return ans;
    }
    
    int dfs(int x,int y,vector<vector<int>>& mat){
        //vis[x][y] = 1;
        //d++;
        //cout<<"d "<<d<<endl;
        if(vis[x][y]!=0)
            return vis[x][y];
        int ans = 0;
        for(int i=0;i<4;i++){
            int newx = x+X[i];
            int newy = y+Y[i];
            if(check(newx,newy)){
                if(mat[newx][newy]>mat[x][y]){
                    ans = max(dfs(newx,newy,mat),ans);          
                }
                           
            }
        }
        vis[x][y] = ans+1;
        return ans+1;
    }
    
    bool check(int x,int y){
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

