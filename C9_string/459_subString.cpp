#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool ans = false;
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int subSize = 1;
        int i;
        for(;subSize<=(n/2);subSize++){
            //cout<<"subSize "<<subSize<<" ";
            if(n%subSize!=0)
                continue;
            for(i=0;(i+subSize)<n;i++){
                if(s[i]!=s[i+subSize]){
                    cout<<s[i]<<" "<<s[i+subSize]<<" ";
                    break;
                }
            }
            //cout<<"haha";
            // cout<<"i "<<i<<" "<<subSize<<endl;
            if((i+subSize==n))
                ans = true;
        }
        return ans;
    }

    bool repeatedSubstringPattern1(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> dp(n+1,0);
        while( i < str.size() ){
            if( str[i] == str[j] ) dp[++i]=++j;
            else if( j == 0 ) i++;
            else j = dp[j];
        }
        for(int i=0;i<=n;i++){
            cout<<dp[i]<<" ";
        }
        return dp[n]&&dp[n]%(n-dp[n])==0;
    }
};


int main(){
    bool ans;
    string s = "abababa";
    ans = Solution().repeatedSubstringPattern1(s);
    cout<<"ans "<<ans;
}