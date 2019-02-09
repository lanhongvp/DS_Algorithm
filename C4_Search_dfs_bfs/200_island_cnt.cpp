#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //const int maxsize=10010;
    int X[4] = {0,0,-1,1};
    int Y[4] = {-1,1,0,0};
    vector<vector<int>> vis;
    int n,m;
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        this->n = n;
        this->m = m;
        int cnt = 0;
        vis.resize(n);
        for(int i=0;i<n;i++)
            vis[i].resize(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                vis[i][j] = 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&(vis[i][j]==0)){
                    cout<<"xixi";
                    //vis[i][j] = 1;
                    dfs(i,j,grid);
                    cnt++;
                } 
            }
        }
        return cnt;
    }
    
    void dfs(int x,int y,vector<vector<char>>& g){
        vis[x][y] = 1;
        cout<<"haha";
        for(int i=0;i<4;i++){
            int newx = x+X[i];
            int newy = y+Y[i];
            if(check(newx,newy)){
                if(g[newx][newy]=='1' &&(vis[newx][newy]==0))
                    dfs(newx,newy,g);
            }
        }
    }
    
    bool check(int x,int y){
        //cout<<"n "<<n<<"m "<<m;
        if((x>=0 && y>=0) &&(x<n && y<m))
            return true;
        else 
            return false;
    }
};

int main(){
    vector<vector<char>> grid;
    grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    int ans;
    ans = Solution().numIslands(grid);
    cout <<"ans "<<ans;
}