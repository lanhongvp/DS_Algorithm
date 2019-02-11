class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> tmp(n+1,0);
        vis = tmp;
        dfs();
        return result;
    }
    
    void dfs(){
        if(tmp.size()==k){
            result.push_back(tmp);
            return;
        }else{
            int start_index = 0;
            if(tmp.size() != 0)
                start_index = tmp[tmp.size()-1];
            for(int i=start_index+1;i<=n;i++){
                //if(vis[i]==0){
                    tmp.push_back(i);
                  //  vis[i] = 1;
                    dfs();
                  //  vis[i] = 0;
                    tmp.pop_back();
                //}
            }
        }
    }
private:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<int> vis;
    int k;
    int n;
};

class Solution1 {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<vector<int>> combine(int n, int k) {
        dfs(0,n,k);
        return ans;
    }
    
    void dfs(int idx,int n,int k){
        if(tmp.size()==k){
            ans.push_back(tmp);
            return;
        }else{
            for(int i=idx+1;i<=n;i++){
                tmp.push_back(i);
                dfs(i,n,k);
                tmp.pop_back();
            }
        }
    }
};