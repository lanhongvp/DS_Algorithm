#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//1.注意一一对应的关系
//2.string.find的使用，巧妙使用解决重复字符串出现的问题
class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
            return a.first>b.first;
        }
    
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back(make_pair(indexes[i],i));
        }
        sort(vp.begin(),vp.end(),cmp);
        for(int i=0;i<n;i++){
            int idx = vp[i].first;
            int pos = vp[i].second;
            if(S.find(sources[pos],idx)==idx){
                S.replace(idx,sources[pos].size(),targets[pos]);
            }
        }
        return S;
    }
};

int main(){
    string S;
    string ans;
    vector<int> indexes;
    vector<string> sources;
    vector<string> targets;
    S = "wreorttvosuidhrxvmvo";
    indexes = {14,12,10,5,0,18};
    sources = {"rxv","dh","ui","ttv","wreor","vo"};
    targets = {"frs","c","ql","qpir","gwbeve","n"};
    ans = Solution().findReplaceString(S,indexes,sources,targets);
    cout<<"ans "<<ans;
}