#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>

using namespace std;
const int maxsize = 1010;
map<string,int> string2int;
map<int,string> int2string;
map<string,int> gang;
//vector<int> G[maxsize];
int D[maxsize][maxsize] = {0};
int P[maxsize] = {0};
int vis[maxsize];
int weight[maxsize];
int n,k;
int num_person=0,cnt=0;

int change(string s){
    if(string2int.find(s)!=string2int.end())
        return string2int[s];
    else{
        string2int[s] = num_person;
        int2string[num_person] = s;
        num_person++;
        return string2int[s];
    }
}

void bfs(int node){
    vis[node] = 1;
    int weight_sum = 0;
    for(int i=0;i<n;i++){
        if()
    }
}

int main(){
    cin>>n>>k;

    string a,b;
    int value;
    for(int i=0;i<n;i++){
        cin>>a>>b>>value;
        int node1 = change(a);
        //cout<<"n1 "<<node1<<" ";
        int node2 = change(b);
        //cout<<"n2 "<<node2<<" ";
        P[node1] += value;
        P[node2] += value;
        D[node1][node2] += value;
        D[node2][node1] += value;
        //cout<<endl;
    }
    bfs();
    //
    cout<<gang.size()<<endl;
    map<string,int>::iterator it;
    for(it=gang.begin();it!=gang.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
}

/*
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
*/
