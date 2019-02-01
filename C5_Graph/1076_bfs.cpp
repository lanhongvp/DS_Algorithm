#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
const int maxsize=1010;
struct node{
    int idx;
    int layer;
};
vector<node> G[maxsize];
int vis[maxsize];
int n,L,k;

void bfs(int id,int& num_cnt){
    node start;
    start.idx = id;
    start.layer = 0;
    queue<node> q;
    q.push(start);
    vis[start.idx] = 1;

    while(!q.empty()){
        node top = q.front();
        q.pop();

        for(unsigned int i=0;i<G[top.idx].size();i++){
            node next = G[top.idx][i];
            next.layer = top.layer+1;
            if(vis[next.idx]==0 && next.layer<=L){
                num_cnt++;
                vis[next.idx] = 1;
                q.push(next);
            }
        }
    }


}

int main(){
    cin>>n>>L;
    node user;
    //建图时，出现的问题，即不要忘记vector的每一个元素是node的结构体
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        user.idx = i;
        int follower;
        for(int j=0;j<num;j++){
            cin>>follower;
            G[follower].push_back(user);
        }
    }
    cin>>k;
    int query_id;
    for(int i=0;i<k;i++){
        cin>>query_id;
        fill(vis,vis+maxsize,0);
        int num_cnt = 0;
        bfs(query_id,num_cnt);
        cout<<num_cnt<<endl;
    }
}
