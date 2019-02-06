#include<iostream>
#include<vector>

using namespace std;
int m = 10;
int n = 10;

int main(){
    vector<vector<int>> dp(m+1, vector<int>(n+1,INT_MAX));
    int m = dp.size();
    int n = dp[0].size();
    cout<<"m1 "<<m<<" "<<"n1 "<<n<<endl;
    dp[m1-1][n1] = 1;
    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}