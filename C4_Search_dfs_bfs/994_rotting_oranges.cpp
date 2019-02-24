class Solution {
public:
    int X[4] = {0,0,-1,1};
    int Y[4] = {1,-1,0,0};
    int n,m;
    //up,down,left,right
    bool check(int x,int y){
        if(x>=0 && y>=0 && x<=n-1 && y<=m-1)
            return true;
        else
            return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>> q;
        if(n==0){
            return 0;
        }
        int size = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                    size++;
                }
            }
        }
        int cnt = 0;
        //int flag = 0;
        while(!q.empty()){
           auto a = q.front();
           q.pop();
            for(int i=0;i<4;i++){
                int newx = a.first + X[i];
                int newy = a.second + Y[i];
                if(check(newx,newy)){
                    if(grid[newx][newy]==1){
                        //flag = 1;
                        grid[newx][newy] = 2;
                        q.push(make_pair(newx,newy));
                    }
                }
            }
            size--;
            if(size==0){
                cnt++;
                size = q.size();
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return cnt>0?cnt-1:cnt;
    }
};