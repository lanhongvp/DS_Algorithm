#include<iostream>

using namespace std;
const int maxsize = 105;
int maze[maxsize][maxsize] = {0};   //运用邻接矩阵建图
int vis[maxsize] = {0};             //标记是否访问过的矩阵
int node_num,edge_num;              //迷宫的点数和边数

int char2int(char c){
    return c-'A';
}

char int2char(int i){
    char tmp = (char)(i+'A');
    return tmp;
}

void dfs(int node){
    vis[node] = 1;
    char tmp_char = int2char(node);
    cout <<tmp_char;
    for(int i=0;i<node_num;i++){
        //cout<<"xixi";
        int tmp_node = i;
        if(vis[tmp_node]==0 && maze[node][i]==1){
            dfs(tmp_node);
        }
    }
}

int main(){
    //int edge_num;
    cin>>node_num>>edge_num;
    char node1,node2;
    for(int i=0;i<edge_num;i++){
        cin>>node1>>node2;
        int node_int1 = char2int(node1);
        int node_int2 = char2int(node2);
        maze[node_int1][node_int2] = 1;
        maze[node_int2][node_int1] = 1;
    }
    //STRAT_NODE开始遍历
    dfs(0);
}

/*
6 5
A B
A D
B C
D F
D E
*/

/*
3 3
A B
A C
B C
*/