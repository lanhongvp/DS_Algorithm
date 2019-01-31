#include<iostream>
#include<queue>
#include<string>

using namespace std;
const int maxsize = 105;
int dist[maxsize];

int main(){
    int n;
    cin>>n;

    priority_queue<int,vector<int>,less<int>>q;
    int value;
    for(int i=0;i<n;i++){
        cin>>value;
        dist[i] = value;
        q.push(dist[i]);
    }
    for(int i=0;i<n;i++){
        cout<<q.top()<<" ";
        q.pop();
    }
}

/*

*/