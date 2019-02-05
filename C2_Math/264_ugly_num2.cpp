#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

const int maxsize=1700;
int ugly_t[maxsize];

class Solution {
public:
    int nthUglyNumber(int n) {
      //1.initial
      set<int> u_table;
      set<int>::iterator it;

      //2.corner case
      if(n==1) return 1;
      // cout<<"xi";

      //3.main pro
      u_table.insert(1);
      // cout<<"wo";
      for(int i=1;i<1690;i++){
        // cout<<"ha";
        u_table.insert(2*i);       
        u_table.insert(3*i);
        u_table.insert(5*i);
      }
      int i=0;
      for(it=u_table.begin();it!=u_table.end();it++){
        // cout<<"it"<<*it<<" ";
        ugly_t[i] = *it;
        if(i==n) break;
        // cout<<"u"<<ugly_t[i]<<" ";
        i++;
      }
      int res = ugly_t[n-1]; 
      return res;
    }
};

int main() {
    int num;
    cin>>num;

    int res = Solution().nthUglyNumber(num);
    cout<<res;
}