#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> indegree(numCourses,0);
        queue<int> q;
        unordered_map<int,vector<int>> dict;
        int cnt = 0;
        if(n==0) return true;
        for(int i=0;i<n;i++){
            dict[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }
        int m = indegree.size();
        for(int i=0;i<m;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            cout<<"top "<<top<<" ";
            q.pop();
            for(unsigned int i=0;i<dict[top].size();i++){
                int tmp = dict[top][i];
                cout<<"tmp "<<tmp<<" ";
                if(--indegree[tmp]==0) q.push(dict[top][i]);
            }
            cnt++;
        }
        return (cnt)==numCourses;
    }
};

int main(){
    bool result;
    vector<pair<int, int>> pre;
    pair<int,int> p1(1,0);
    pre.push_back(p1);
    result = Solution().canFinish(2,pre);
    cout<<"result "<<result;
}