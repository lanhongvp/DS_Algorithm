#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

//单源最短路
using namespace std;
const int maxsize = 105;
const int INF = 0X3FFFFFFF;
int col[maxsize] = {0};
int dist[maxsize];
vector<int> G[maxsize];
vector<int> D[maxsize];
int n,m,s;

int find_min(){
    int min_node = -1;
    int min_dist =  0x3fffffff;
    for(int i=0;i<n;i++){
        if(col[i]==0 && dist[i]<min_dist){
            min_node = i;
            min_dist = dist[i];
        }
    }
    return min_node;
}

void dijsktra(int node){
    dist[node] = 0;

    int next_node;
    while((next_node = find_min())!=-1){
        col[next_node] = 1;
        //cout<<"next "<<next_node<<" ";
        for(unsigned int i=0;i<G[next_node].size();i++){
            int tmp_node = G[next_node][i];
            int tmp_weight = D[next_node][i];
            if(col[tmp_node]==0){
                int tmp_dist = dist[next_node]+tmp_weight; 
                if(tmp_dist<dist[tmp_node]){
                dist[tmp_node] = dist[next_node]+tmp_weight;
                //col[tmp_node] = 1;
                }
            }

        }
    }

}

int main(){
    cin>>n>>m>>s;

    int node1,node2,distance;
    for(int i=0;i<m;i++){
        cin>>node1>>node2>>distance;
        G[node1].push_back(node2);
        G[node2].push_back(node1);
        D[node1].push_back(distance);
        D[node2].push_back(distance);
    }
    fill(dist,dist+maxsize,INF);
    dijsktra(s);
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
}

/*
6 8 0
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3
*/