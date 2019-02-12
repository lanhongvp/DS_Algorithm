class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        int cnt = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            //cout<<"i "<<i<<" ";
            for(int j=1;j<=m;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = 0;
                }
                cnt = max(cnt,dp[i][j]);
            }
        }
        return cnt;
    }
};