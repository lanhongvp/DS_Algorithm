#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
const int maxsize=105;
const int INF= 0x3fffffff;
vector<int> G[maxsize];
vector<int> W[maxsize];
int col[maxsize];
int dist[maxsize];
int n,m;

int find_min(int node){
    int min_node = -1;
    int min_dist = 0x3fffffff;
    for(unsigned int i=0;i<G[node].size();i++){
        int tmp_node = G[node][i];
        int tmp_weight = W[node][i];
        if(!col[tmp_node]){
            if(dist[node]+tmp_weight<dist[tmp_node]){
                dist[tmp_node] = dist[node]+tmp_weight;
                if(dist[node]+tmp_weight<min_dist){
                    min_node = tmp_node;
                    min_dist = dist[node]+tmp_weight;
                }
            }
        }
    }
    return min_node;
}

void dij(int node){
    dist[node] = 0;
    queue<int> q;
    q.push(node);
    col[node] = 1;

    while(!q.empty()){
        int top_node = q.front();
        q.pop();
        int next_node = find_min(top_node);
        if(next_node==-1)
            break;
        col[next_node] = 1;
        q.push(next_node);
    }
}

int main(){
    cin>>n>>m;
    int start_node;
    cin>>start_node;
    int node1,node2,weight;
    for(int i=0;i<m;i++){
        cin>>node1>>node2>>weight;
        G[node1].push_back(node2);
        G[node2].push_back(node1);
        W[node1].push_back(weight);
        W[node2].push_back(weight);
    }
    fill(dist,dist+maxsize,INF);
    dij(start_node);
    
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