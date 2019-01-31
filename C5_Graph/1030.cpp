#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxsize = 510;
const int INF = 0X3FFFFFFF;
int n,m,s,d;
vector<int> G[maxsize],D[maxsize],C[maxsize];
int vis[maxsize]={0};
int dist[maxsize];
int cost[maxsize];
int path_cnt[maxsize];
int pre[maxsize]={-1};

int find_min(){
    int min_node = -1;
    int min_dist = INF;
    int min_cost = 0;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            if(dist[i]<min_dist){
                min_dist = dist[i];
                min_node = i;
            }
        }
    }
    return min_node;
}

void dijsktra(int node){
    dist[node] = 0;
    cost[node] = 0;
    int next_node;
    while((next_node = find_min())!=-1){
        //cout<<"xi";
        vis[next_node] = 1;
        for(unsigned int i=0;i<G[next_node].size();i++){
            int tmp_node = G[next_node][i];
            int tmp_weight = D[next_node][i];
            int tmp_cost = C[next_node][i];
            if(vis[tmp_node]==0){
                if(dist[next_node]+tmp_weight<dist[tmp_node]){
                    dist[tmp_node] = dist[next_node]+tmp_weight;
                    cost[tmp_node] = cost[next_node]+tmp_cost;
                    pre[tmp_node] = next_node;
                }
                else if(dist[next_node]+tmp_weight==dist[tmp_node] && cost[next_node]+tmp_cost<cost[tmp_node]){
                    cost[tmp_node] = cost[next_node]+tmp_cost;
                    pre[tmp_node] = next_node;
                }
            }
        }
    }
}

void dfs(int v){
    if(v==s){    
        cout<<s<<" ";
        return;
    }
    dfs(pre[v]);
    cout<<v<<" ";
}

int main(){
    cin>>n>>m>>s>>d;

    int node1,node2,weight,costv;
    for(int i=0;i<m;i++){
        cin>>node1>>node2>>weight>>costv;
        G[node1].push_back(node2);
        G[node2].push_back(node1);
        D[node1].push_back(weight);
        D[node2].push_back(weight);
        C[node1].push_back(costv);
        C[node2].push_back(costv);
    }
    fill(dist,dist+maxsize,INF);
    fill(cost,cost+maxsize,INF);
    dijsktra(s);
    dfs(d);
    cout<<dist[d]<<" "<<cost[d];

}

/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20 
2 3 1 20
*/