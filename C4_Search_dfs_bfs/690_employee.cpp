#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    unordered_map<int,vector<int>> dict;
    queue<pair<int,int>> q;
    vector<int> val;
    void build_graph(vector<Employee*> employees){
        for(int i=0;i<employees.size();i++){
            vector<int> tmp;
            tmp = employees[i]->subordinates;
            val[employees[i]->id] = employees[i]->importance;               
            for(int j=0;j<tmp.size();j++){
                dict[employees[i]->id].push_back(tmp[j]);
            }
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        //build
        build_graph(employees);
        int im_val = val[id];
        for(int i=0;i<dict[id].size();i++){
            im_val += val[dict[id][i]];
        }
        return im_val;
    }
};

int main(){
    
}