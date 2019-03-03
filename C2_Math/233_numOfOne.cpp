class Solution {
public:
    int countDigitOne(int n) {
        if(n<1)
            return 0;
        int len = getLenOfNum(n);
        if(len==1)
            return 1;
        int div = (int)pow(10,len-1);
        int first = n/div;
        int firstOfOne = first == 1 ? n%div+1:div; 
        int otherOfOne = first*(len-1)*(div/10);
        return firstOfOne+otherOfOne+countDigitOne(n%div);
    }
    
    int getLenOfNum(int n){
        int len = 0;
        while(n!=0){
            //cout<<"len";
            len ++;
            n = n/10;
        }
        return len;
    }
};