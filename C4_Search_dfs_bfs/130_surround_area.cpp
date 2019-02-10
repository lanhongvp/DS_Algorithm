#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> vis;
    int n,m;
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    
    void solve(vector<vector<char>>& board) {       
        int n = board.size();
        if(n==0) return;
        vis.resize(n);
        int m = board[0].size();
        if(m==0) return;
        for(int i=0;i<n;i++)
            vis[i].resize(m);
        //return;
        this->n = n;
        this->m = m;
        //return;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j] = 0;
            }
        }
        //return;
        //boudary judge
        //first and last row
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' &&(vis[0][i]==0)){
                sur(0,i,board);
                //cout<<"first row ";                
            }
            if(board[n-1][i]=='O'&&(vis[n-1][i]==0)){
                sur(n-1,i,board);
                //cout<<"last row ";                
            }
            //cout<<board[n-1][i]<<" ";
        }
        //return;
        //first and last column
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' &&(vis[i][0]==0)){
                sur(i,0,board);
                // cout<<"f c ";
            }
            if(board[i][m-1]=='O'&&(vis[i][m-1]==0)){
                sur(i,m-1,board);
                // cout<<"L c ";
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                if(board[i][j]=='E')
                    board[i][j] = 'O';
            }
        }
    }
    
    void sur(int x,int y,vector<vector<char>>& b){
        // cout<<"haha";
        vis[x][y] = 1;
        b[x][y]='E';
        for(int i=0;i<4;i++){
            int newx = x+X[i];
            int newy = y+Y[i];
            if(check(newx,newy)){
                if(b[newx][newy]=='O' &&(vis[newx][newy]==0)){
                    sur(newx,newy,b);
                }   
            }
        }
    }
    
    bool check(int x,int y){
        if((x>=0 && y>=0) && (x<n &&y<m))
            return true;
        else
            return false;
    }
};

int main(){
    vector<vector<char>> b,b1;
    int n = 4;
    int m = 6;
    // int n,m;
    // cin>>n>>m;
    // char c;
    b = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},
        {'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    b1 = {{}};
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>c;
    //         b[i][j] = c; 
    //     }
    // }

    Solution().solve(b);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }

}