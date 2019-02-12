class Solution {
public:
    int trailingZeroes(int n) {
      //1.initial
      int cnt = 0;
      //2.corner case
      if(n==0) return 0;
      //3.main pro
      while(n>0){
        cnt+=n/5;
        n/=5;
      }
      return cnt;
    }
};