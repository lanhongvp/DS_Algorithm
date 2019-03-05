class Solution {
public:
    int findNthDigit(int n) {
        if(n<10){
            return n;
        }
        int len = 1;
        long long bitNum = 0;
        while(bitNum<n){
            bitNum = bitSum(len);
            len++;
        }
        len = len - 1;
        //cout<<"bitNum "<<bitNum<<" ";
        long long bitBefore = bitSum(len-1);
        //cout<<"bitBefore "<<bitBefore<<" ";
        int pos,modNum,idx;
        cout<<"len "<<len<<" ";
        modNum = (n-bitBefore)%len;
        //cout<<"modNum "<<modNum<<" ";
        //idx = len-modNum-1;
        if(modNum==0){
            pos = (n-bitBefore)/len;
            idx = len-1;
        }else{
            pos = (n-bitBefore)/len + 1;
            idx = modNum-1;
        }
        //int tmp = len;
        long long num = 0;
        long long digit;
        while(len>1){
            len--;
            num += 9*pow(10,len-1);
        }
        digit = num + pos;
        //cout<<"digit "<<digit<<" ";
        //cout<<"idx "<<idx;
        return (to_string(digit)[idx]-'0');
    }
    
    long long bitSum(int len){
        long long sum = 0;
        long long exp;
        long long cnt = 9;
        while(len>=1){
            //cout<<"hha";
            exp = pow(10,len-1);
            sum += cnt*exp*len;
            len--;
        }
        return sum;
    }
};