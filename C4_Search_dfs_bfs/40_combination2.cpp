class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    set<vector<int>> s;
    int n;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        n = candidates.size();
        this->n = n;
        dfs(0,0,candidates,target);
        return ans;
    }
    
    void dfs(int idx,int sum,vector<int>& c,int t){
        if(sum==t){
            ans.push_back(tmp);
                return;
        }
        if(sum>t){
            return;
        }
        for(int i=idx;i<n;i++){
            if(i>0 && (c[i]==c[i-1])&&(i>idx))
                continue;
            tmp.push_back(c[i]);
            dfs(i+1,sum+c[i],c,t);
            tmp.pop_back();
        }
    }
};