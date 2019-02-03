#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;
const int maxsize=100;
//int dp[maxsize][maxsize];

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        //1.Initial
        int dp[m+1][n+1];
        //2.Corner case
        if(word1.empty())
          return word2.size();
        if(word2.empty())
          return word1.size();
        //3.State transform
        for(int i=0;i<=m;i++){
          for(int j=0;j<=n;j++){
            if(i==0&&j==0)
              dp[0][0] = 0;
            else{
              if(i==0)
                dp[0][j]=j;
              else if(j==0)
                dp[i][0]=i;
              else{
                //There are 3 states
                int del = dp[i][j-1]+1;
                int ins = dp[i-1][j]+1;
                int rep = dp[i-1][j-1]+((word1[i-1]==word2[j-1])?0:1);
                dp[i][j] = min(min(del,ins),rep);
              }
            }      
          }
        }
        //cout<<m<<n<<endl;
      return dp[m][n];
    }
};

int main(){
    string str1,str2;
    cin>>str1>>str2;

    int cnt=Solution().minDistance(str1,str2);
    // cout<<"cnt "<<cnt;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}