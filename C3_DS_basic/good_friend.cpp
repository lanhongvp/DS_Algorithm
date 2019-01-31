#include<iostream>

using namespace std;
const int maxsize = 105;
int graph[maxsize][maxsize] = {0};
int vis[maxsize] = {0};
int cnt = 0;
int n,m;

void bfs(int node){
    vis[node] = 1;
    int flag = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&graph[node][i])
            flag = 1;
    }
    if(flag) cnt++;
}

int main(){
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for(int i=1;i<=n;i++){
        bfs(i);
    }
    cout <<cnt;
}
/*
4 2
1 4
2 3
*/
/*
7 5
1 2
2 3
3 1
1 4
5 6
*/