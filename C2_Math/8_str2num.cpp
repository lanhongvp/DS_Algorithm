#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
      //1.initial
      long long ans=0;
      int flag=false;  //sign
      int st=0;
      const long long max_ot = 0x100000000;
      //2.corner case
      while(str[st]==' ') st++;
      if(str[st]=='+'){
        st++;
      }
      else{
        if(str[st]=='-'){
          flag=true;
          st++;
        }
      }
      //3.transform
      for(int i=st;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9'){
          ans = ans*10 + str[i]-'0';
          if(ans>max_ot) ans = max_ot;            
        }
        else
          break;
      }

     if(flag) ans = -ans;
     if(ans>INT_MAX) ans=INT_MAX;
     if(ans<INT_MIN) ans=INT_MIN;
      return ans;
    }
};

int main(){
    string str;
    cin>>str;

    int ans = Solution().myAtoi(str);
    cout<<ans;
}