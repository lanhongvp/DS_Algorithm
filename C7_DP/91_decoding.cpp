#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
      //1.Initialization
      int n=s.size();
      int dp[n+1];
      //2.Corner case
      if(s[0]=='0')
        return 0;
      if(s.size()==1)
        return 1;
      //3.State transform
      dp[0] = 1;
      dp[1] = 1;
    //   cout<<"size"<<s.size()<<" ";
      for(int i=1;i<=s.size();i++){
        cout<<i<<"->";
        if(s[i]!='0'){
            if(i>1 && ((s[i-2]<='1'&&s[i-2]>'0')||(s[i-2]>'0'&&s[i-2]<='2')&&(s[i-1]<='6'&&s[i-1]>'0'))){
                dp[i] = dp[i-1]+dp[i-2];
                cout<<i<<"ha";
            }   
            else{
                cout<<i<<" xi";
                dp[i] = dp[i-1];
            }
        }
        else{
            cout<<"i"<<i;
            dp[i] = dp[i-1];
        }
        
        cout<<endl;
      }
      return dp[n];
    }
};
int main(){
    string str;
    cin>>str;
    int cnt = Solution().numDecodings(str);
    cout<<cnt;
}