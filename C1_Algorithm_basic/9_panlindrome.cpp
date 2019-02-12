class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0 && x!=0)) return false;
        int r_num=0;
        while(x>r_num){
            r_num = r_num*10+x%10;
            x = x/10;
        }
        return x==r_num || r_num/10==x;
    }
};