#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;
const int maxsize = 2010;
//vector<int> G[maxsize];
int D[maxsize][maxsize] = {0};   //边权矩阵
int P[maxsize];            //点权数组
int vis[maxsize];          //记录是否被访问过
map<string,int> string2int; 
map<int,string> int2string;
map<string,int> gang;      //结果记录
int n,k;
int idx=0;

int change(string s){
    if(string2int.find(s)!=string2int.end())
        return string2int[s];
    else{
        string2int[s] = idx;
        int2string[idx] = s;
        idx++;
        return string2int[s];
    }
}

void dfs(int now_vis,int& head_node,int& num_member,int& total_w){
    num_member++;
    vis[now_vis] = 1;
    if(P[now_vis]>P[head_node]){
        head_node = now_vis;
    }
    for(int i=0;i<n;i++){
        if(D[now_vis][i]){
            total_w += D[now_vis][i];
            D[now_vis][i] = D[i][now_vis] = 0;
            //vis[i] = 1;
        if(vis[i]==0)
            dfs(i,head_node,num_member,total_w);
        }
    }
}

int main(){
    cin>>n>>k;

    string a,b;
    int value;
    for(int i=0;i<n;i++){
        cin>>a>>b>>value;
        int id1 = change(a);
        int id2 = change(b);
        D[id1][id2] += value;
        D[id2][id1] += value;
        P[id1] += value;
        P[id2] += value;
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0){
        int head_node=i,num_member=0,total_w=0;
        dfs(i,head_node,num_member,total_w);
        if(num_member>2&&total_w>k){
            gang[int2string[head_node]] = num_member;
        }
        }
        
    }
    cout<<gang.size()<<endl;
    map<string,int>::iterator it;
    for(it=gang.begin();it!=gang.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}