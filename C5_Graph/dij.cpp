#include<iostream>
#include<vector>
using namespace std;
const int maxsize = 1000;

vector<int> G[maxsize];
vector<int> D[maxsize];
int dist[maxsize];
int col[maxsize];

class dijsktra{
public:
    int findMin(int n){
        int minDist = 0x3fffffff;
        int minNode = -1;
        for(int i=0;i<G[n].size();i++){
            if((D[n][i]+dist[n]<minDist)&&(col[n]==0)){
                minNode = i;
                minDist = D[n][i]+dist[n];
            }
        }
        return minNode;
    }

    void dij(int s,int t,int n){
        dist[s] = 0;
        //bfs
        //col[s] = 1;
        while(1){
            int minNode = findMin(n);
            col[minNode] = 1;
            if(minNode==t){
                break;
            }
            for(int i=0;i<G[minNode].size();i++){
                int node = G[minNode][i];
                if(col[node]==0){
                    int newDist = dist[minNode]+D[node][i];
                    if(newDist<dist[node]){
                        dist[node] = newDist;
                    }
                }
            }
        }
    }
};

int main(){
    int N,E;
    cin>>N>>E;
    int node1,node2,weight;
    int start,target;
    for(int i=0;i<E;i++){
        cin>>node1>>node2>>weight;
        G[node1].push_back(node2);
        G[node2].push_back(node1);
        D[node1].push_back(weight);
        D[node1].push_back(weight);
    }
    dijsktra().dij();
}