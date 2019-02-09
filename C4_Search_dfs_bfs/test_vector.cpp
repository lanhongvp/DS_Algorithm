#include<iostream>
#include<vector>

using namespace std;
const int maxsize = 10;
int main(){
    vector<int> tmp(maxsize,0);
    vector<int> vis(4,tmp);
    // v = {1,2,3,4};
    cout<<vis[0][0];
    cout<<vis.size();
}