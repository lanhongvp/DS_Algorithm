#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n==0) return ans;
        dfs(0,0,1,n,k);
        return ans;
    }
    
    void dfs(int nowk,int sum,int num,int n,int k){
        //cout<<"sum "<<sum<<" nowk "<<nowk<<endl;
        if((sum==n) && (nowk==k)){
            ans.push_back(tmp);
            return;
        }
        if(sum>n||nowk>=k||num>9){
            return;
        }
        tmp.push_back(num);
        dfs(nowk+1,sum+num,num+1,n,k);
        tmp.pop_back();
        dfs(nowk,sum,num+1,n,k);
    }
};

int main(){
    vector<vector<int>> ans;
    ans = Solution().combinationSum3(3,7);
    cout<<ans.size();
}