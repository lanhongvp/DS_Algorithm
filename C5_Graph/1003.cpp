#include<iostream>
#include<vector>

using namespace std;
const int maxsize = 510;
const int INF = 0x3fffffff;
int n,m,s,d;
vector<int> G[maxsize];
vector<int> D[maxsize];
int col[maxsize]={0};
int dist[maxsize];
int path_cnt[maxsize];
int raw_people[maxsize],people[maxsize];
int max_people=0;

int find_min(){
    int min_node=-1;
    int min_dist=0x3fffffff;
    for(int i=0;i<n;i++){
        if((col[i]==0) && (dist[i]<min_dist)){
            min_dist = dist[i];
            min_node = i;
        }
    }
    return min_node;
}

void dij(int node0){
    dist[node0] = 0;
    path_cnt[node0] = 1;
    int node;
    while(find_min()!=-1){
        node = find_min();
        col[node] = 1;
        //cout<<"node "<<node;
        //max_people += people[node];    
        for(unsigned int i=0;i<G[node].size();i++){
            int tmp_node = G[node][i];
            int tmp_weight = D[node][i];
            //int tmp_people = people[tmp_node];
            if(col[tmp_node]==0 && dist[node]+tmp_weight<dist[tmp_node]){
                dist[tmp_node] = dist[node]+tmp_weight;
                path_cnt[tmp_node] = path_cnt[node];
                people[tmp_node] += people[node];
                //max_people += tmp_people;
            }
            else if(col[tmp_node]==0 && dist[node]+tmp_weight==dist[tmp_node]){
                path_cnt[tmp_node] += path_cnt[node];
                if(people[node]+raw_people[tmp_node]>people[tmp_node])
                    people[tmp_node] = people[node]+raw_people[tmp_node];
            }
        }
    }
}

int main(){
    cin>>n>>m>>s>>d;
    
    int res_people;
    for(int i=0;i<n;i++){
        cin>>res_people;
        raw_people[i] = res_people;
        people[i] = res_people;
    }
    //people = raw_people;
    int node1,node2,distance;
    for(int i=0;i<m;i++){
        cin>>node1>>node2>>distance;
        G[node1].push_back(node2);
        G[node2].push_back(node1);
        D[node1].push_back(distance);
        D[node2].push_back(distance);
    }

    fill(dist,dist+maxsize,INF);
    dij(s);

    cout<<path_cnt[d]<<" "<<people[d];
}   
/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/